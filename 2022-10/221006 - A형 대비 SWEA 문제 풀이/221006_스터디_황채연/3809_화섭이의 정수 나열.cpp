#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int T, N;
string in;
int DAT[1000];

int Solve() {
	int start = 1;
	while (1) {
		if (start == 4) break;
		for (int i = 0; i < in.size() - start + 1; ++i) {
			if (start > 1 && in[i] == '0') continue;
			string temp = "";
			for (int j = i; j < i + start; ++j) {
				temp += in[j];
			}
			
			int tar = stoi(temp);
			DAT[tar] = 1;
		}

		if (start == 1) {
			for (int i = 0; i < 10; ++i) {
				if (DAT[i] == 0) return i;
			}
		}
		if (start == 2) {
			for (int i = 10; i < 100; ++i) {
				if (DAT[i] == 0) return i;
			}
		}
		if (start == 3) {
			for (int i = 100; i < 1000; ++i) {
				if (DAT[i] == 0) return i;
			}
		}
		
		start++;
	}
}

void init() {
	in = "";
	memset(DAT, 0, sizeof(DAT));
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			char cnum;
			cin >> cnum;
			in += cnum;
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}