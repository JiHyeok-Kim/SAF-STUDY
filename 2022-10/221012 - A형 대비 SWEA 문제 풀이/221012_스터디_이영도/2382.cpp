// 미생물 격리 
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct {
	int y, x, num, dir;
}str;
int N, M, K;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
vector<str> vec;

bool compare(str A, str B) { // sort compare func
	// y asc
	if (A.y < B.y) return 1;
	if (A.y > B.y) return 0;

	// x asc
	if (A.x < B.x) return 1;
	if (A.x > B.x) return 0;

	// num asc
	if (A.num < B.num) return 1;
	if (A.num > B.num) return 0;
}

void move() { // move function
	
	for (int i = 0; i < vec.size(); i++) { // move move ~
		int ny = vec[i].y + dy[vec[i].dir];
		int nx = vec[i].x + dx[vec[i].dir];

		vec[i].y = ny;
		vec[i].x = nx;
	}

	int de = 0;
	sort(vec.begin(), vec.end(), compare); // sort
	int de1 = 0;
	for (int i = 1; i < vec.size(); i++) { // check 1
		// empty is ignore
		if (vec[i - 1].num == 0) continue;

		// same location check
		if (vec[i - 1].y == vec[i].y &&
			vec[i - 1].x == vec[i].x){
			vec[i].num = vec[i - 1].num + vec[i].num;
			vec[i - 1].num = 0;
		}
	}

	for (int i = 0; i < vec.size(); i++) { // check 2
		// empty is ignore
		if (vec[i].num == 0) continue;

		// red zone check
		if (vec[i].y == 0 || vec[i].x == 0 ||
			vec[i].y == N - 1 || vec[i].x == N - 1) {
			vec[i].num = vec[i].num / 2;
			if (vec[i].dir == 1) vec[i].dir = 2;
			else if (vec[i].dir == 2) vec[i].dir = 1;
			else if (vec[i].dir == 3) vec[i].dir = 4;
			else if (vec[i].dir == 4) vec[i].dir = 3;
		}
	}
}

void init() { // initialization function
	vec.clear();
}

int main() {
	int T;
	cin >> T;
	
	for (int tc = 0; tc < T; tc++) { // test case
		init();
 		// 셀(map) N, 격리 시간 M, 미생물 군집 수 K
		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) { // input
			int y, x, n, d;
			cin >> y >> x >> n >> d;
			vec.push_back({ y, x, n, d });
		}

		// 격리시간 
		for (int i = 0; i < M; i++) { move(); }

		int ret = 0;
		for (int i = 0; i < vec.size(); i++) { // result
			ret += vec[i].num; 
		}

		cout << "#" << tc + 1 << " " << ret << endl;
	}

	return 0;
}