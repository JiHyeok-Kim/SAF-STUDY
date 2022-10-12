#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;



struct Wait {
	int tp;
	int customer;
	int idx;
	int time;
};

bool operator<(Wait a, Wait b) {
	if (a.time == b.time) {
		if (a.tp == b.tp) {
			return a.idx > b.idx;
		}
		return a.tp < b.tp;
	}
	return a.time > b.time;
}

priority_queue<Wait> customer;
queue<int> receptionCustomer;
queue<int> repairCustomer;
priority_queue<int, vector<int>, greater<int>> reception;
priority_queue<int, vector<int>, greater<int>> repair;
int C[10];
int R[10];
vector<int>cUsed[10];
vector<int>rUsed[10];
int T, N, M, K, A, B;

bool checker[1001];

void init() {
	while (!customer.empty())
		customer.pop();
	while (!receptionCustomer.empty())
		receptionCustomer.pop();
	while (!repairCustomer.empty())
		repairCustomer.pop();
	while (!reception.empty())
		reception.pop();
	while (!repair.empty())
		repair.pop();
	memset(C, 0, sizeof(C));
	memset(R, 0, sizeof(R));
	for (int a = 0; a < 10; ++a) {
		cUsed[a].clear();
	}
	for (int b = 0; b < 10; ++b) {
		rUsed[b].clear();
	}
	memset(checker, 0, sizeof(checker));
}
void simul(int before, int time) {

	for (int a = before; a <= time; ++a) {
		while (!customer.empty() && customer.top().time == a) {
			Wait now = customer.top();
			customer.pop();
			int cusID = now.customer;
			int ID = now.idx;
			if (now.tp == 0) {
				repairCustomer.push(cusID);
				reception.push(ID);
			}
			else {
				repair.push(ID);
			}
		}
		if (!reception.empty() && !receptionCustomer.empty()) {
			while (!reception.empty()) {
				int cusID = receptionCustomer.front();
				receptionCustomer.pop();
				int ID = reception.top();
				reception.pop();
				customer.push({ 0,cusID,ID,a + C[ID] });
				cUsed[ID].push_back(cusID);
				if (receptionCustomer.empty())
					break;
			}
		}
		if (!repair.empty() && !repairCustomer.empty()) {
			while (!repair.empty()) {
				int cusID = repairCustomer.front();
				repairCustomer.pop();
				int ID = repair.top();
				repair.pop();

				customer.push({ 1,cusID,ID,a + R[ID] });
				rUsed[ID].push_back(cusID);
				if (repairCustomer.empty())
					break;
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		init();
		cin >> N >> M >> K >> A >> B;
		int before = 0;
		for (int a = 1; a <= N; ++a) {
			reception.push(a);
			cin >> C[a];
		}
		for (int b = 1; b <= M; ++b) {
			repair.push(b);
			cin >> R[b];
		}
		for (int a = 1; a <= K; ++a) {
			int tmp;
			cin >> tmp;
			simul(before, tmp - 1);
			receptionCustomer.push(a);
			simul(tmp, tmp);
			before = tmp;
		}
		simul(before, 20000);
		for (int a = 0; a < cUsed[A].size(); ++a) {
			checker[cUsed[A][a]] = 1;
		}
		int ans = 0;
		for (int a = 0; a < rUsed[B].size(); ++a) {
			if (checker[rUsed[B][a]]) {
				ans += rUsed[B][a];
			}
		}
		if (ans == 0)
			cout << "#" << t << " " << -1 << "\n";
		else
			cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
