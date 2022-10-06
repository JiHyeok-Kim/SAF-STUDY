#include <iostream>
#include <queue>
using namespace std;

int n, m;
int R[110];
int park[110];
int W[2100];
int inOut;
int ans;

queue<int> q;
queue<int> waitQ;

void init() {
	ans = 0;
	for (int i = 0; i < 110; i++) {
		R[i] = 0;
		park[i] = 0;
	}
	for (int i = 0; i < 2100; i++) {
		W[i] = 0;
	}
}

void input() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> R[i];
		park[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> W[i];
	}
	for (int i = 0; i < m * 2; i++) {
		cin >> inOut;
		q.push(inOut);
	}
}

int isPossible() {
	for (int i = 0; i < n; i++) {
		if (park[i] == -1) {
			return i;
		}
	}
	return -1;
}

void naga(int now) {
	now *= -1;
	for (int i = 0; i < n; i++) {
		if (park[i] == now) {
			park[i] = -1;
			return;
		}
	}
}


void solve() {
	int bin;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int flag = 0;

		if (now > 0) 
		{
			bin = isPossible();

			if (bin != -1) {
				park[bin] = now;
				ans += W[now - 1] * R[bin];
			}
			else waitQ.push(now);
			
		}
		else if (now < 0) 
		{
			naga(now);
			flag = 1;
		}

		if (flag == 1 && !waitQ.empty()) {
			now = waitQ.front();
			waitQ.pop();
			bin = isPossible();
			park[bin] = now;
			ans += W[now - 1] * R[bin];
		}
	}

}

int main() 
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}
	
	return 0;
}