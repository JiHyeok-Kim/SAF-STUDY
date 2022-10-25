#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// 10개 1초
// 키입력 string 길이 1~1000
// 단어 개수 1~1000
// 2~9 눌렀을 때 나올 수 있는 알파벳 정리
// 문자열 길이랑 비교하는 문자의 길이가 같아야 비교가능
int n, ans;
string num;
string word[11] = { 
	"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
vector<string> tong;
string temp;

void init() {
	ans = 0;
	tong.clear();
}
void input() {
	cin >> num >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		tong.push_back(temp);
	}
}


void solve() {
	int len = num.size();

	for (int i = 0; i < n; i++) {
		if (tong[i].size() != len) continue;
		int flag = 0;
		for (int k = 0; k < len; k++) {
			int tar = num[k] - '0';
			if (word[tar].find(tong[i][k]) == -1) 
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		ans++;
	}

}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
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