
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



string makeAnswer(int h, int m, int s) {
	string tmp = "";
	if (h < 10)
		tmp = "0" + to_string(h);
	else
		tmp = to_string(h);

	tmp += ":";

	if (m < 10)
		tmp += "0" + to_string(m);
	else
		tmp += to_string(m);

	tmp += ":";

	if (s < 10)
		tmp += "0" + to_string(s);
	else
		tmp += to_string(s);

	return tmp;
}
string nowTime;
string apointTime;
int nowH, nowM, nowS;
int apointH, apointM, apointS;
int T;


bool check() {
	if (nowH > apointH) {
		return 1;
	}
	if (nowH == apointH && nowM > apointM)
		return 1;

	if (nowH == apointH && nowM == apointM && nowS > apointS)
		return 1;


	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin); 
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> nowTime >> apointTime;

		nowH = stoi(nowTime.substr(0, 2));
		nowM = stoi(nowTime.substr(3, 2));
		nowS = stoi(nowTime.substr(6, 2));
		apointH = stoi(apointTime.substr(0, 2));
		apointM = stoi(apointTime.substr(3, 2));
		apointS = stoi(apointTime.substr(6, 2));

		string answer;
		if (check()) {
			int tmpH = apointH + 23 - nowH;
			int tmpM = apointM +59 - nowM;
			int tmpS = apointS + 60 - nowS;

			tmpM += (tmpS / 60);
			tmpH += (tmpM / 60);

			tmpS = tmpS % 60;
			tmpM = tmpM % 60;

			
			answer = makeAnswer(tmpH, tmpM, tmpS);
		}
		else {
			int tmpH;
			int tmpS;
			int tmpM;
			if (nowS > apointS) {
				tmpS = 60 - nowS + apointS;
				nowM++;
			}
			else {
				tmpS = apointS - nowS;
			}

			if (nowM > apointM) {
				tmpM = 60 - nowM + apointM;
				nowH++;
			}
			else {
				tmpM = apointM - nowM;
			}

			tmpH = apointH - nowH;

			answer = makeAnswer(tmpH, tmpM, tmpS);
		}
		cout << "#"<<t<< " "<<answer << "\n";
	}
}
