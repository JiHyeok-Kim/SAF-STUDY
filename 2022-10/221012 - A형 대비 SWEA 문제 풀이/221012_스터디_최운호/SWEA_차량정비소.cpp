#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
	int cost;
	bool empty;
	int uT;
};

struct customer {
	int cN;
	int aT;
	int recN;
};

struct info {
	int rcN;
	int rpN;
};

bool operator<(customer A, customer B) {
	if (A.aT > B.aT) return true;
	if (A.aT < B.aT) return false;

	if (A.recN > B.recN) return true;
	if (A.recN < B.recN) return false;
}

int N, M, K, A, B;

state rec[10];
state rep[10];

info arr[1001];

queue<customer> q;

priority_queue<customer> pq;

int recUse() {
	for (int i = 1; i <= N; i++) {
		if (rec[i].empty) {
			rec[i].empty = false;
			return i;
		}
	}
	return 0;
}

int repUse() {
	for (int i = 1; i <= M; i++) {
		if (rep[i].empty) {
			rep[i].empty = false;
			return i;
		}
	}
	return 0;
}

void goTime() {
	for (int i = 1; i <= N; i++) {
		if (rec[i].empty) continue;
		rec[i].uT++;
	}
	for (int i = 1; i <= M; i++) {
		if (rep[i].empty) continue;
		rep[i].uT++;
	}
}

void check() {
	for (int i = 1; i <= N; i++) {
		if (rec[i].empty) continue;
		if (rec[i].uT == rec[i].cost) {
			rec[i].empty = true;
			rec[i].uT = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (rep[i].empty) continue;
		if (rep[i].uT == rep[i].cost) {
			rep[i].empty = true;
			rep[i].uT = 0;
		}
	}
}

void go() {
	int curT = 0;

	while (1) {

		check();

		for (int i = 0; i < q.size(); i++) {
			customer first = q.front();

			if (first.aT > curT) break;
			int ret = recUse();
			if (ret == 0) break;
			arr[first.cN].rcN = ret;
			pq.push({first.cN, curT+rec[ret].cost, ret});
			q.pop();
			i--;
		}

		for (int i = 0; i < pq.size(); i++) {
			customer first = pq.top();

			if (first.aT > curT) break;
			int ret = repUse();
			if (ret == 0) break;
			arr[first.cN].rpN = ret;
			pq.pop();
			i--;
		}

		if (q.empty() && pq.empty()) break;

		goTime();

		curT++;
	}

}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++) {
			int c;
			cin >> c;
			rec[i] = { c, true, 0 };
		}
		for (int i = 1; i <= M; i++) {
			int c;
			cin >> c;
			rep[i] = { c, true, 0 };
		}
		for (int i = 1; i <= K; i++) {
			int arrive;
			cin >> arrive;
			q.push({ i, arrive, 0 });
		}

		go();

		int answer = 0;

		for (int i = 1; i <= K; i++) {
			if (arr[i].rcN == A && arr[i].rpN == B) answer += i;
		}

		if (answer == 0) answer = -1;
		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}