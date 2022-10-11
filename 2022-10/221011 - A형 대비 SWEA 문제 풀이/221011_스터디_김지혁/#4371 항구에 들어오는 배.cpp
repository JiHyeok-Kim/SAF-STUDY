#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int date;
	int mark;
};

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
		int N, n, last, ans = 0;
		vector<int> happy(1);
		vector<Node> ship;
		cin >> N;
		cin >> happy[0];
		for (int i = 1; i < N; i++)
		{
			cin >> n;
			happy.push_back(n);
			int date = happy[i] - 1;
			ship.push_back({ date, 1 });
		}

		for (int i = 0; i < ship.size(); i++) {
			for (int j = i + 1; j < ship.size(); j++) {
				if (ship[j].date % ship[i].date == 0) {
					ship[j].mark = 0;
				}
			}
		}
		for (auto& i : ship) {
			ans += i.mark;
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}