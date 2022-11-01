#include <iostream>
#include <cmath>
using namespace std;

string num2, num3;
int len2, len3;

void init()
{
	cin >> num2 >> num3;
	len2 = num2.length();
	len3 = num3.length();

	return;
}

int trans(string num, int n) 
{
	int num10 = 0;
	int idx = -1;
	for (int i = num.length() - 1; i >= 0; i--)
	{
		idx++;
		num10 += (num[i] - '0') * pow(n, idx);
	}

	return num10;
}

int solve() 
{
	int n2 = trans(num2, 2);
	int n3 = trans(num3, 3);
	int idx = -1;
	for (int i = len3 - 1; i >= 0; i--) {
		idx++;
		for (int j = 0; j < 3; j++) {
			int n = num3[i] - '0';
			if (i == 0 && j == 0) continue;
			if (n == j) continue;
			int temp = n3;
			n3 -= n * pow(3, idx);
			n3 += j * pow(3, idx);
			int cmp = n3 - n2;
			if ((cmp) % 2 == 0 || abs(cmp) == 1) {
				if (cmp < 0) {
					for (int i = 0; i < 40; i++) {
						if (abs(cmp) < pow(2, i)) break;
						if (abs(cmp) == pow(2, i) && num2[len2 - 1 - i] == '1') {
							return n3;
						}
					}
				}
				else if (cmp > 0) {
					for (int i = 0; i < len2; i++) {
						if (cmp < pow(2, i)) break;
						if (cmp == pow(2, i) && num2[len2 - 1 - i] == '0') {
							return n3;
						}
					}
				}
			}
			n3 = temp;
		}
	}

	return 0;
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
		cout << "#" << tc << " " << solve() << "\n";
	}


	return 0;
}