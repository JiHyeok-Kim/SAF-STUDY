#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, maxi, lenM;
int num[1000];
int gop[1000000];

void init()
{
	maxi = -1;
	lenM = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			gop[idx] = num[i] * num[j];
			idx++;
		}
	}

	string str;
	for (int i = 0; i < idx; i++) {
		if (gop[i] < maxi) continue;
		int flag = 0;
		str = to_string(gop[i]);
		char ch = 0;
		for (int j = 0; j < str.length(); j++) {
			if (ch > str[j]) flag = 1;
			else if (ch < str[j]) ch = str[j];
			if (flag == 1) break;
		}
		if (flag == 1) continue;
		maxi = gop[i];
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << maxi << "\n";
	}


	return 0;
}