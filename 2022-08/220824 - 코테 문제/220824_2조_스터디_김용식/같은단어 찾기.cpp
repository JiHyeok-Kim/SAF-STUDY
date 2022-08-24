#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string str;
string comp;
string real;

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	cin >> str;
	cin >> comp;

	int a=0;
	int cnt = 0;
	int max = -2134567890;
	int idx=0;
	int bigu = 0;
	while (a < comp.length()) {
		cnt = 0;
		int start = 0;
		while (1) {
			cnt = 0;
			bigu = a;
			int b = str.find(comp[a], start);
			if (b == -1)break;
			for (int i = b; i < str.length(); i++) {
				if (comp[bigu] == str[i]) {
					bigu++;
					cnt++;
					idx = i;
				}
				else if (a+i >= comp.length() || i>=str.length()) {
					break;
				}
				else if(comp[a + i] != str[i]) {
					break;
				}
			}
			if (max < cnt) {
				max = cnt;
				real = str.substr(b, idx - b+1);
			}
			start = b + 1;
		}
		a++;
	}
	cout << real;


	return 0;
}