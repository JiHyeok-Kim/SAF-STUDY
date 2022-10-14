#include <iostream>
using namespace std;

int price[4];
int plan[13];
int ans;

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> price[i];
	}
	for (int i = 1; i < 13; i++) {
		cin >> plan[i];
	}
}

void dfs(int month, int sum) {
	if (month == 13) {
		if (ans > sum) {
			ans = sum;
		}
		return;
	}
	// 1일, 1달, 3달, 1년
	for (int choice = 0; choice < 4; choice++) {
		if (choice == 0) {
			dfs(month + 1, sum + plan[month] * price[choice]);
		}
		else if (choice == 1) {
			dfs(month + 1, sum + price[choice]);
		}
		else if (choice == 2 && month <= 10) {
			dfs(month + 3, sum + price[choice]);
		}
		else if (choice == 3 && month == 1) {
			dfs(month + 12, sum + price[choice]);
		}

	}
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		ans = 21e8;
		input();
		dfs(1, 0);

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}