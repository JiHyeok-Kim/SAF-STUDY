#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>

using namespace std;


string input;
char croak[6] = "croak";
bool used[2501];
int flag = 1;
void dfs(int start) {
	int idx = 0;
	for (int a = start; a < input.length(); ++a) {
		if (used[a] == 0 && input[a] == croak[idx]) {
			used[a] = 1;
			idx = (idx + 1) % 5;
		}
	}
	if (idx != 0)
		flag = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		memset(used, 0, sizeof(used));
		flag = 0;
		cin >> input;
		int ans = 0;
		if(input.length() %5 ==0){
			flag = 1;
			for (int a = 0; a < input.length(); ++a) {
				if (used[a] == 0){
					if (input[a] == 'c') {
						++ans;
						dfs(a);
						if (flag == 0)
							break;
					}
					else {
						flag = 0;
						break;
					}
				}
			}
		}
		if (flag)
			cout << "#"<<t<< " " <<ans << "\n";
		else
			cout << "#" << t << " -1\n";
	}
}
