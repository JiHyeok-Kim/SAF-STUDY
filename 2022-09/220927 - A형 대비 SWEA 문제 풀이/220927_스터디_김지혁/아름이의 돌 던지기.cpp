#include <iostream>
#include <cstring>
using namespace std;

int dat[100001] = { 0 };

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;
		memset(dat, 0, sizeof(dat));

		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			dat[abs(n)]++;
		}
		
		int maxi = 0;
		int idx = -1;
		for (auto& i : dat) {
			idx++;
			if (i > 0) {
				cout << "#" << tc << " " << idx << " " << i << "\n";
				break;
			}
		}
	}

	return 0;
}