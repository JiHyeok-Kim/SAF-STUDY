#include <iostream>
#include <vector>
using namespace std;
struct temp {
	int h;
	int cnt;
	int used;
};

int map[20][20];
int n, x;
int result = 0;

void check(int arr[20]) {
	vector<temp> v;

	int cnt = 1;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			for (int j = 0; j < cnt; j++) v.push_back({ arr[i], cnt, 0 });
		}
		else if (arr[i] != arr[i + 1]) {
			for(int j=0;j<cnt;j++) v.push_back({ arr[i], cnt, 0 });
			flag = 0;
			cnt = 0;
		}
		cnt++;
	}

	if (flag) {
		result++;
		return;
	}

	for (int i = 0; i < v.size() - 1; i++) {
		if (abs(v[i].h - v[i + 1].h) > 1) return;
		else if (v[i].h == v[i + 1].h) continue;

		if (v[i].h > v[i + 1].h) {
			if (v[i + 1].cnt < x) return;
			for (int j = i + 1; j <= i + x; j++) {
				if (v[j].used == 1) return;
				v[j].used = 1;
			}
		}
		else {
			if (v[i].cnt < x) return;
			for (int j = i; j >= i - x + 1; j--) {
				if (v[j].used == 1) return;
				v[j].used = 1;
			}
		}
	}
	
	result++;
	return;
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> n >> x;
		result = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			int arr[20] = { 0 };
			for (int j = 0; j < n; j++) {
				arr[j] = map[i][j];
			}
			check(arr);
		}

		for (int i = 0; i < n; i++) {
			int arr[20] = { 0 };
			for (int j = 0; j < n; j++) {
				arr[j] = map[j][i];
			}
			check(arr);
		}

		cout << "#" << t << " " << result << '\n';
	}

	return 0;
}