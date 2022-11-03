#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int N, idx;

unordered_map<string, int> um;
vector<int> v[200];
int visited[200];

void init()
{
	um.clear();

	for (int i = 0; i < 200; i++) {
		v[i].clear();
		visited[i] = 0;
	}
	idx = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string player1, player2;
		cin >> player1 >> player2;
		if (um.count(player1) == 0) um[player1] = idx++;
		if (um.count(player2) == 0) um[player2] = idx++;
		v[um[player1]].push_back(um[player2]);
		v[um[player2]].push_back(um[player1]);
	}
}

void getSearch(int now, int color)
{
	visited[now] = color;

	for (auto loop : v[now])
	{
		if (visited[loop] != 0) continue;
		getSearch(loop, 3 - color);
	}
}

bool check(int now, int color)
{
	for (int loop : v[now])
	{
		if (visited[now] == visited[loop]) return false;
	}
	return true;
}

bool solution()
{
	for (int i = 0; i < idx; i++) {
		if (visited[i] != 0) continue;
		getSearch(i, 1);
	}

	for (int i = 0; i < idx; i++) {
		if (!check(i, visited[i])) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		if (solution()) cout << "#" << t << " Yes" << '\n';
		else cout << "#" << t << " No" << '\n';
	}
	return 0;
}