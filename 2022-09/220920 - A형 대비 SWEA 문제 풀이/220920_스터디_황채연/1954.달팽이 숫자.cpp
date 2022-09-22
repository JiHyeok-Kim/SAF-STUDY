#include <iostream>
#include <vector>
using namespace std;

int T, N;
int MAP[10][10];

// 우 하 좌 상
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
vector<int> v;

void changeMap() {
	v.clear();
	int sy = 0, sx = 0, snum = 1;
	MAP[sy][sx] = snum;
	int start = N - 1;
	int d = 0;
	int sum = 0;
	for (int i = 0; i < start; ++i) {
		v.push_back(d);
	}
	sum = start;
	d++;
	for (int i = 0; i < 100; ++i) {
		int sp = start - i / 2;
		for (int j = 0; j < sp; ++j) {
			v.push_back(d);
		}
		sum += sp;
		if (sum == N * N) break;
		d = (d + 1) % 4;
	}

	for (int i = 0; i < v.size(); ++i) {
		sy += dy[v[i]];
		sx += dx[v[i]];
		MAP[sy][sx] = ++snum;
	}
}

void Solve(int tc) {
	changeMap();
	
	cout << "#" << tc << "\n";
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cout << MAP[y][x] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		Solve(tc);
	}
	return 0;
}