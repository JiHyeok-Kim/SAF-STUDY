#include <iostream>
using namespace std;

int charger[110000], car[110000];
int G, P;

int Find(int now) {
	if (now < 0) return 0;
	if (charger[now] == now) return now;
	return charger[now] = Find(charger[now]);
}

int Union(int car) {
	int pCar = Find(charger[car]);
	if (pCar <= 0) return 1;
	charger[pCar]--;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		charger[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= P; i++) {
		cin >> car[i];
		if (Union(car[i])) {
			cout << ans;
			return 0;
		}
		ans++;
	}
	return 0;
}