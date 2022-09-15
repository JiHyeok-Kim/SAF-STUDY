#include <iostream>
using namespace std;

int d, oM, tM, y;
int result = 21e8; int dCost[13] = { 0 };

void go(int lev, int cost) {
	if (lev > 12) {
		result = min(result, cost);
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (i == 0) go(lev + 1, cost + dCost[lev]);
		else go(lev + 3, cost + tM);
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> d >> oM >> tM >> y;
		result = 21e8;
		for (int i = 1; i <= 12; i++) {
			int days;
			cin >> days;
			dCost[i] = days * d;
			if (dCost[i] > oM) dCost[i] = oM;
		}
		
		go(1, 0);

		result = min(result, y);

		cout << "#" << t << " " << result << '\n';
	}

	return 0;
}