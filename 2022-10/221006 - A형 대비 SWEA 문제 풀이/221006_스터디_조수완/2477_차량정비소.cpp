#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int result, N, M, K, A, B;
int customer[4][1100];
int reception[2][15];
int repair[2][15];
struct cmp {
	bool operator() (int v, int t) {
		if (customer[1][t] != customer[1][v]) return customer[1][t] < customer[1][v];
		return customer[2][t] < customer[2][v];
	}
};
priority_queue<int, vector<int>, cmp> waiting;

void input() {
	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++) cin >> reception[0][i];
	for (int i = 1; i <= M; i++) cin >> repair[0][i];
	for (int i = 1; i <= K; i++) cin >> customer[0][i];
}
void init() {
	result = 0;
	for (int i = 1; i <= N; i++) reception[1][i] = 0;
	for (int i = 1; i <= M; i++) repair[1][i] = 0;
}
void findResult() {
	for (int i = 1; i <= K; i++) {
		if (customer[2][i] == A && customer[3][i] == B) result += i;
	}
	if (result == 0) result = -1;
}
int findRecDesk(int id) {
	int mini = 21e8;
	int minidx = 0;
	for (int i = 1; i <= N; i++) {
		if (customer[0][id] >= reception[1][i]) {
			reception[1][i] = customer[0][id] + reception[0][i];
			customer[1][id] = reception[1][i];
			return i;
		}
		else {
			if (reception[1][i] < mini) {
				mini = reception[1][i];
				minidx = i;
			}
		}
	}
	reception[1][minidx] += reception[0][minidx];
	customer[1][id] = reception[1][minidx];
	return minidx;
}
void Reception() {
	for (int i = 1; i <= K; i++) {
		int desk = findRecDesk(i);
		customer[2][i] = desk;
		waiting.push(i);
	}
}
int findRepDesk(int id) {
	int mini = 21e8;
	int minidx = 0;
	for (int i = 1; i <= M; i++) {
		if (customer[1][id] >= repair[1][i]) {
			repair[1][i] = customer[1][id] + repair[0][i];
			return i;
		}
		else {
			if (repair[1][i] < mini) {
				mini = repair[1][i];
				minidx = i;
			}
		}
	}
	repair[1][minidx] += repair[0][minidx];
	return minidx;
}
void Repair() {
	while (!waiting.empty()) {
		int now = waiting.top();
		waiting.pop();
		int desk = findRepDesk(now);
		customer[3][now] = desk;
	}
}
void sol() {
	Reception();
	Repair();
	findResult();
}
int main() {
	freopen_s(new FILE * , "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		init();
		sol();
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}