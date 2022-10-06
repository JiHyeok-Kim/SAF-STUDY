#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int parking_info[101];
int car_info[2001];


int T, N, M;

priority_queue<int,vector<int>,greater<int>> parking;
queue<int> car;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		int salary = 0;
		for (int a = 1; a <= N; ++a) {
			cin >> parking_info[a];
			parking.push(a);
		}
		for (int b = 1; b <= M; ++b) {
			cin >> car_info[b];
		}

		for (int a = 0; a < M * 2; ++a) {
			int tmp;
			cin >> tmp;

			if (tmp > 0) {
				if (parking.empty()) {
					car.push(tmp);
				}
				else {
					int idx = parking.top();
					parking.pop();
					if (!car.empty()) {
						car.push(tmp);
						tmp = car.front();
						car.pop();
					}
					salary = salary + car_info[tmp] * parking_info[idx];
					car_info[tmp] = idx;
				}
			}
			else {
				tmp = -tmp;
				int parking_place = car_info[tmp];
				if (!car.empty()) {
					int car_idx = car.front();
					car.pop();
					salary = salary + car_info[car_idx] * parking_info[parking_place];
					car_info[car_idx] = parking_place;
				}
				else {
					parking.push(parking_place);
				}
			}
		}
		while (!parking.empty())
			parking.pop();
		cout << "#"<<t<<" " <<salary << "\n";
	}

}
