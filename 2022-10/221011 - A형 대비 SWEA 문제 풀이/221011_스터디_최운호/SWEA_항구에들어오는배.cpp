#include <iostream>
using namespace std;

struct info
{
	int day;
	bool state;
};

int N;
int answer;
info ship[5000];

void getShipVal() {

	for (int i = 1; i < N; i++) {
		if (ship[i].state) continue;
		ship[i].state = true;
		answer++;
		int period = ship[i].day - ship[0].day;
		int temp = ship[i].day;
		for (int j = i + 1; j < N; j++) {
			if (ship[j].day - period == temp) {
				ship[j].state = true;
				temp = ship[j].day;
			}
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N;
		answer = 0;
		for (int i = 0; i < N; i++) {
			int d;
			cin >> d;
			ship[i] = { d,false };
		}

		getShipVal();

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}