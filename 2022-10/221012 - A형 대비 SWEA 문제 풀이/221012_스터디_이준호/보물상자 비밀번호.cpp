#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, K, Rotate, ans;
string pw;
vector<int> tong;

void init() {
	ans = 0;
	Rotate = 0;
	tong.clear();
}

void input() {
	cin >> N >> K >> pw;
}
 
void RotatePW() {
	string tt = "";
	tt += pw[pw.size() - 1];
	for (int i = 0; i < pw.size() - 1; i++) {
		tt += pw[i];
	}
	pw = tt;
}

int toDec(string temp) {
	int sum = 0;
	int a;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] >= '0' && temp[i] <= '9') {
			a = temp[i] - '0';
		}
		else {
			a = temp[i] - 55;
		}
		sum += a * pow(16, temp.size() - 1 - i);
	}
	return sum;
}

void findNum() {
	sort(tong.begin(), tong.end(), greater<int>());
	int idx = 0;
	for (int i = 0; i < tong.size(); i++) {
		if (idx == K - 1) {
			ans = tong[i];
			break;
		}
		if (tong[i] != tong[i + 1]) idx++;

	}

}
void solve() {
	Rotate = N / 4;
	int start;
	string temp;
	int tar;
	// 스트링 전체 회전
	for (int k = 0; k < Rotate; k++) {
		if (k > 0) RotatePW();
		start = 0;
		for (int i = 0; i < 4; i++) 
		{
			temp = pw.substr(start, Rotate);
			tar = toDec(temp);
			tong.push_back(tar);
			start += Rotate;
		}
	}

	findNum();
}


int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}