#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int idx;
	int sum;
};
int ans, cost[4], month[12], tempAns;
int price[12], used[12];
vector<Node> three;

void init() {
	for (int i = 0; i < 12; i++) used[i] = 0;
}
void cmpYear() {
	int tempSum = 0;
	for (int i = 0; i < 12; i++) {
		tempSum += price[i];
	}
	ans = min(tempSum, cost[3]);
}
void cmpYear1(int tempPrice[12]) {
	int tempSum = 0;
	for (int i = 0; i < 12; i++) {
		tempSum += tempPrice[i];
	}
	tempAns = min(tempSum, tempAns);
}

int isPossible(int start) {
	for (int i = 0; i < 3; i++) {
		if (used[start + i] == 1)return 0;
	}
	return 1;
}
int path[12];
void threeDfs(int lev) {
	if (lev == three.size()) {
		int tempPrice[12] = { 0 };
		init();
		for (int j = 0; j < 12; j++) tempPrice[j] = price[j];
		for (int i = 0; i < three.size(); i++) {
			if (path[i] == 0) continue;
			if (!isPossible(three[i].idx)) continue;
			int start = three[i].idx;
			for (int j = 0; j < 3; j++) {
				if (j == 0) tempPrice[start + j] = cost[2];
				else tempPrice[start + j] = 0;
				used[start + j] = 1;
			}
			cmpYear1(tempPrice);
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		path[lev] = i;
		threeDfs(lev + 1);
	}
}


void threeMon() {
	tempAns = 21e8;
	for (int i = 0; i < 10; i++) {
		int tempSum = price[i] + price[i + 1] + price[i + 2];
		if (cost[2] < tempSum) {
			three.push_back({ i,tempSum });
		}
	}
	threeDfs(0);
}
void dayORmon() {
	for (int i = 0; i < 12; i++) {
		int temp = min(cost[1], month[i] * cost[0]);
		price[i] = temp;
	}
}

void sol() {
	ans = 21e8;
	dayORmon();
	threeMon();
	if (three.empty()) cmpYear();
	else ans = min(cost[3], tempAns);
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		three.clear();
		init();
		for (int i = 0; i < 4; i++) cin >> cost[i];
		for (int i = 0; i < 12; i++) cin >> month[i];
		sol();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}