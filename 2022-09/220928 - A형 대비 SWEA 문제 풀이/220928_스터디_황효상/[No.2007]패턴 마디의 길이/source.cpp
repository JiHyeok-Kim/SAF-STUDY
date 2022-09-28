#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;

int N;
void input() {
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		string input;
		cin >> input;

		for (int a = 1; a <= 10; ++a) {
			string tmp = input.substr(0, a);
			int idx = input.find(tmp, a);
			if (idx == a + 1) {
				cout <<"#"<<t<< " "<< a+1 << "\n";
				break;
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	input();
	return 0;
}
