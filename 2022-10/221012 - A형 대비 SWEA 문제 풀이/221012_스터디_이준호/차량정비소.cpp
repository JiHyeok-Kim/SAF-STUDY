#include <iostream>
#include <queue>
using namespace std;

int N, M, K, walA, walB;
int procDK[10];
int procJB[10];
int t, idx, ans;

struct Node {
	int num;
	int time;
	int changu1;
	int changu2;
};
struct Node2 {
	int num;
	int changu1;
};

Node DK[10];
Node JB[10];
queue<int> timeQ;

queue<int> waitDKQ;
queue<Node2> waitJBQ;

void init() {
	for (int i = 0; i < 10; i++) {
		procDK[i] = 0;
		procJB[i] = 0;
	}
}
void input() {
	idx = 1;
	ans = 0;
	cin >> N >> M >> K >> walA >> walB;
	for (int i = 1; i <= N; i++) {
		cin >> procDK[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> procJB[i];
	}
	for (int i = 0; i < K; i++) {
		cin >> t;
		timeQ.push(t);
	}
}

// ���� ���� �Լ�
bool go() {
	for (int bunho = 1; bunho <= N; bunho++) {
		if (DK[bunho].num != 0) return 1;
	}
	for (int bunho = 1; bunho <= M; bunho++) {
		if (JB[bunho].num != 0) return 1;
	}
	if (!waitDKQ.empty() || !waitJBQ.empty()) return 1;
	return 0;
}

void isWallet(int y, int x, int idx) {
	if (y == walA && x == walB) {
		ans += idx;
	}
}

bool isFull(int choice) {
	if (choice == 1) {
		for (int bunho = 1; bunho <= N; bunho++) {
			if (DK[bunho].num == 0) return 0;
		}
		return 1;
	}
	else if (choice == 2) {
		for (int bunho = 1; bunho <= M; bunho++) {
			if (JB[bunho].num == 0) return 0;
		}
		return 1;
	}
	return 1;
}

void GoDK() {

	while (1) {
		// ������Ⱑ ���ų� DK�� ������ ����
		if (waitDKQ.empty() || isFull(1)) break;

		int now = waitDKQ.front();
		waitDKQ.pop();

		for (int bunho = 1; bunho <= N; bunho++) {
			if (DK[bunho].num == 0) {
				DK[bunho].num = now;
				DK[bunho].time = procDK[bunho];
				DK[bunho].changu1 = bunho;
				break;
			}
		}
	}
}

void GoJB() {

	while (1) {
		// �����Ⱑ ���ų� JB�� ������ ����
		if (waitJBQ.empty() || isFull(2)) break;

		Node2 now = waitJBQ.front();
		waitJBQ.pop();

		for (int bunho = 1; bunho <= M; bunho++) {
			if (JB[bunho].num == 0) {
				JB[bunho].num = now.num;
				JB[bunho].time = procJB[bunho];
				JB[bunho].changu1 = now.changu1;
				JB[bunho].changu2 = bunho;
				break;
			}
		}

	}

}

void outPush() {
	int flag1 = 0;
	int flag2 = 0;
	for (int bunho = 1; bunho <= N; bunho++) {
		if (DK[bunho].num != 0 && DK[bunho].time == 0) {
			waitJBQ.push({ DK[bunho].num, DK[bunho].changu1 });
			DK[bunho].num = 0;
			DK[bunho].changu1 = 0;
			flag1 = 1;
		}
	}
	for (int bunho = 1; bunho <= M; bunho++) {
		if (JB[bunho].num != 0 && JB[bunho].time == 0) {
			isWallet(JB[bunho].changu1, JB[bunho].changu2, JB[bunho].num);
			JB[bunho].num = 0;
			JB[bunho].changu1 = 0;
			JB[bunho].changu2 = 0;
			flag2 = 1;
		}
	}
	if (flag1 == 1) GoDK();
	else if (flag2 == 1) GoJB();
}

void proc() {
	int flag = 0;
	for (int bunho = 1; bunho <= N; bunho++) {
		if (DK[bunho].time != 0) {
			DK[bunho].time -= 1;
			flag = 1;
		}
		if (JB[bunho].time != 0) {
			JB[bunho].time -= 1;
			flag = 1;
		}
	}
	if (flag == 1) {
		outPush();
	}

}

void GoShift() {

	// ������� -> ��������ũ
	GoDK();

	// ��������ũ �� �� ������ 
	// ��������ũ ���������� ������� Ǫ�� && ������� -> ��������ũ
	// ����� �� �� ������
	// ������ġ Ȯ���ϰ� ����� ������ && ������ -> �����
	proc();

	// ������ -> �����
	GoJB();
}

void solve() {
	int before = timeQ.front();

	// ó���� ���� �Ƚ�Ű���� start ����
	int start = 1;
	int now, timedif;
	int t = 0;
	while (start == 1 || go()) {
		
		if (!timeQ.empty()) {
			now = timeQ.front();
			timedif = now - before;
			if (timedif == 0) {
				timeQ.pop();
				waitDKQ.push(idx);
			}
			else if (timedif != 0) {
				start = 0;
				for (int i = 0; i < timedif; i++) {
					GoShift();
				}
				waitDKQ.push(idx);
				timeQ.pop();
			}
			idx++;
			before = now;
			t += timedif;
		}
		else {
			while (go()) {
				GoShift();
				t++;
			}
		}
		
	}

}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();

		if (ans == 0) ans = -1;
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}