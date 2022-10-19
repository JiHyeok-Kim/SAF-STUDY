#include <iostream>
#include <cmath>
#include <string>
using namespace std;

char D;
int A, B;
int num[500000] = { 0 };

void init()
{
	num[0] = 2;

	int cnt;
	int idx = 0;
	for (int i = 3; i < 1000000; i += 2) {
		cnt = 0;
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) cnt++;
			if (cnt >= 2) break;
		}
		if (cnt == 1) {
			idx++;
			num[idx] = i;
		}
	}

	return;
}

int ans()
{
	int result = 0;
	for (auto& i : num)
	{
		if (i < A) continue;
		if (i > B) break;
		string str = to_string(i);
		int len = str.length();
		for (int j = 0; j < len; j++) {
			if (str[j] == D) {
				result++;
				break;
			}
		}
	}

	return result;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> A >> B;
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}
