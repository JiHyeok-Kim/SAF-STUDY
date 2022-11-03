#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

#define Team1 1
#define Team2 2

int N;
unordered_map<string, vector<string>> um;
unordered_map<string, int> visited;

void init()
{
	um.clear();
	visited.clear();

	cin >> N;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		um[str1].push_back(str2);
		um[str2].push_back(str1);
		visited[str1] = 0;
		visited[str2] = 0;
	}

	return;
}

void DFS(string now)
{
	if (visited[now] == 0) visited[now] = Team1;

	for (auto &i : um[now]) 
	{
		if (visited[i] == 0)
		{
			if (visited[now] == Team1) visited[i] = Team2;
			else if (visited[now] == Team2) visited[i] = Team1;

			DFS(i);
		}
	}

	return;
}

void solve()
{
	int idx = -1;
	for (auto &i : um) {
		if (visited[i.first] == 0) {
			DFS(i.first);
		}
	}

	return;
}

bool check()
{
	for (auto &i : um) {
		for (auto &j : i.second) {
			if (visited[i.first] == visited[j]) return false;
		}
	}

	return true;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		solve();
		cout << "#" << tc;
		if (check() == true) cout << " Yes\n";
		else cout << " No\n";
	}

	return 0;
}