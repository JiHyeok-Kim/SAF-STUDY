#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int K;
string str[5];

void init()
{	
	cin >> K;
	for (int i = 1; i <= 4; i++) {
		str[i] = "";
		for (int j = 0; j < 8; j++) {
			char ch;
			cin >> ch;
			str[i] += ch;
		}
	}

	return;
}

void rtn(int idx, int dt, int direct)
{
	if (idx == 0 || idx == 5) return;
	if (idx + 1 < 5 && direct >= 0) {
		if (str[idx][2] != str[idx + 1][6]) rtn(idx + 1, dt * -1, 1);
	}
	if (idx - 1 > 0 && direct <= 0) {
		if (str[idx][6] != str[idx - 1][2]) rtn(idx - 1, dt * -1, -1);
	}

	char chin;
	int chout;
	if (dt == 1) chout = 7;
	else chout = 0;
	chin = str[idx][chout];
	str[idx].erase(chout, 1);
	if (dt == 1) {
		str[idx] = chin + str[idx];
	}
	else {
		str[idx] += chin;
	}

	return;
}

int score()
{
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (str[i][0] == '1') sum += pow(2, i - 1);
	}

	return sum;
}

int main() // N 0, S 1;
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) 
	{
		init();

		for (int i = 0; i < K; i++) {
			int idx, dt;
			cin >> idx >> dt;
			rtn(idx, dt, 0);
		}

		int ans = score();
		cout << "#" << tc << " " << ans << "\n";
	}



	return 0;
}