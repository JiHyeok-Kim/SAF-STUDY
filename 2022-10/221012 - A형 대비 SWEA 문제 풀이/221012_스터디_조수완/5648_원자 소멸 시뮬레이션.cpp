#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int y, x;
	int K, dir;
	int dead;
};
vector<Node> arr;
int N;
int drY[4] = { 1,-1,0,0 };
int drX[4] = { 0,0,-1,1 };
int map[4400][4400];

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		arr.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int y, x, k, dir;
			cin >> x >> y >> dir >> k;
			arr.push_back({ (2 * y) + 2000,(2 * x) + 2000,k,dir,0 });
		}
		int flag = 1, ans = 0;
		while (flag) {
			flag = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i].dead == 1) continue;
				int ny = arr[i].y + drY[arr[i].dir];
				int nx = arr[i].x + drX[arr[i].dir];
				if (ny < 0 || nx < 0 || ny > 4000 || nx > 4000) {
					arr[i].dead = 1;
					continue;
				}
				flag = 1;
				arr[i].y = ny;
				arr[i].x = nx;
				map[ny][nx]++;
			}
			if (flag) {
				for (int i = 0; i < N; i++) {
					if (arr[i].dead == 1) continue;
					if (map[arr[i].y][arr[i].x] > 1) {
						for (int j = 0; j < N; j++) {
							if (arr[j].dead == 0 && arr[j].y == arr[i].y && arr[j].x == arr[i].x) {
								arr[j].dead = 1;
								ans += arr[j].K;
							}
						}
					}
					map[arr[i].y][arr[i].x] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}