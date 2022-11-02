#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

void init()
{
	um.clear();
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		string str;
		cin >> str;
		um[str]++;
	}

	for (int i = 0; i < b; i++) {
		string str;
		cin >> str;
		um[str]++;
	}

	return;
}

int ans()
{
	int cnt = 0;
	for (auto& i : um) {
		if (i.second == 2) cnt++;
	}

	return cnt;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}