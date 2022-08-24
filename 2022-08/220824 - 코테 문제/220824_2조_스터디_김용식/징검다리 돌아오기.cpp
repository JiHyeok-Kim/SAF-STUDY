#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Arr[11] = { 0,3,1,2,1,3,2,1,2,1,0 };
int arrIdx = 0;
void dfs(int now) {
	if (arrIdx >= 10) {
		cout << "도착 ";
		return;
	}
	
	cout << Arr[arrIdx] << " ";
	int next = now+Arr[arrIdx];
	arrIdx += Arr[now];
	dfs(next);
	arrIdx -= Arr[now];
	cout << Arr[arrIdx] << " ";
	


}


int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	arrIdx = n;
	cout << "시작"<<" ";
	dfs(n);
	cout << "시작";
	return 0;
}