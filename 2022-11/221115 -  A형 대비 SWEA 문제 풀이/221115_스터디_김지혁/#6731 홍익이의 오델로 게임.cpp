#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
string map[1000];
int row[1000];
int col[1000];

void init()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));

	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
		int cnt = 0;
		for (int x = 0; x < N; x++)
			if (map[y][x] == 'B') {
				cnt++;
				col[x]++;
			}
		row[y] = cnt;
	}

	return;
}

int solve()
{
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int flip = 0;
			if (map[y][x] == 'B') flip--;
			flip += row[y] + col[x];
			if (flip % 2 == 1) cnt++;
		}
	}

	return cnt;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
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