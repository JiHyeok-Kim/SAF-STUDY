#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int T, N;
vector<int> pickA, pickB;
bool visited[20];
int v[20][20];
int pickIdx[10];
int mini = 21e8;
int sumA, sumB;

void calcPickSum() {
	for (int i = 0; i < pickA.size() - 1; ++i) {
		for (int j = i + 1; j < pickA.size(); ++j) {
			sumA += v[pickA[i]][pickA[j]] + v[pickA[j]][pickA[i]];
			sumB += v[pickB[i]][pickB[j]] + v[pickB[j]][pickB[i]];
		}
	}
}

int calcSum() {
	// pickA, pickB 각각 2개씩 더해서 sum return
	sumA = 0, sumB = 0;
	calcPickSum();
	return abs(sumA - sumB);
}

void DFS(int cnt, int sp) {
	if (cnt == N / 2) {
		// todo something...
		for (int i = 0; i < pickA.size(); ++i) {
			pickIdx[pickA[i]] = 1;
		}
		for (int i = 0; i < N; ++i) {
			if (pickIdx[i] == 0) pickB.push_back(i);
		}
		//

		int point = calcSum();
		if (mini > point) mini = point;

		//
		pickB.clear();
		for (int i = 0; i < N; ++i) {
			pickIdx[i] = 0;
		}
		return;
	}

	for (int i = sp; i < N; ++i) {
		if (visited[i] == true) continue;
		visited[i] = true;
		pickA.push_back(i);
		DFS(cnt + 1, i);
		pickA.pop_back();
		visited[i] = false;
	}
}

int Solve() {
	DFS(0, 0);
	return mini;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N; 
		mini = 21e8;
		pickA.clear();
		pickB.clear();
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cin >> v[y][x];
			}
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}