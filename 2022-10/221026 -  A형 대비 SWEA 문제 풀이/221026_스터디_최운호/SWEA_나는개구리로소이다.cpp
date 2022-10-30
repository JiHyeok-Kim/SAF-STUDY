#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string roar;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> roar;
		int answer = 0;
		int valid[5] = { 0 };
		for (char ch : roar) {
			if (ch == 'c') valid[0]++;
			else if (ch == 'r' && valid[0] > valid[1]) valid[1]++;
			else if (ch == 'o' && valid[1] > valid[2]) valid[2]++;
			else if (ch == 'a' && valid[2] > valid[3]) valid[3]++;
			else if (ch == 'k' && valid[3] > 0) {
				answer = max(answer, valid[0]);
				for (int i = 0; i < 4; i++) valid[i]--;
			}
			else {
				answer = -1;
				break;
			}
		}

		if (valid[0] != 0) answer = -1;

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}