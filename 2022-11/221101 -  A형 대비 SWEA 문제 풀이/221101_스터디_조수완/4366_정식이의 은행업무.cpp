#include <iostream>
#include <string>
#include <vector>
using namespace std;
string bin, thr;
vector<long long> binTong;
vector<long long> thrTong;

void mkBin(string tar) {
	for (int i = 0; i < tar.length(); i++) {
		string temp = tar;
		if (temp[i] == '0')temp[i] = '1';
		else temp[i] = '0';
		long long num = temp[temp.length()-1]-'0', gop = 1;
		for (int j = temp.length() - 2; j >= 0; j--) {
			num += (temp[j] - '0') * (gop *= 2);
		}
		binTong.push_back(num);
	}
}
void mkThr(string tar) {
	for (int i = 0; i < tar.length(); i++) {
		for (int k = 0; k < 3; k++) {
			if (tar[i] == k + '0') continue;
			//if (i == 0 && k == 0) continue;
			string temp = tar;
			temp[i] = k + '0';
			long long num = temp[temp.length() - 1]-'0', gop = 1;
			for (int j = temp.length() - 2; j >= 0; j--) {
				num += (temp[j] - '0') * (gop *= 3);
			}
			thrTong.push_back(num);
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		binTong.clear();
		thrTong.clear();
		cin >> bin >> thr;
		mkBin(bin);
		mkThr(thr);
		int flag = 0;
		for (int i = 0; i < binTong.size(); i++) {
			for (int j = 0; j < thrTong.size(); j++) {
				if (binTong[i] == thrTong[j]) {
					cout << "#" << t << " " << binTong[i] << "\n";
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}