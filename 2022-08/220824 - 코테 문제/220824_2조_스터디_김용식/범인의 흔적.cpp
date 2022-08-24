#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int evid[7] = {-1,0,0,1,2,4,4};
int timeStamp[7] = {8,3,5,6,8,9,10};
int startIdx = -2134567890;
int arriveIdx = 0;
void dfs(int now) {
	if (now == 0) {
		cout << now << "번" << "index(출발)" << '\n';
		return;
	}
	int next = evid[now];
	dfs(next);
	cout << now << "번" << "index" << "("<<timeStamp[now]<<"시" << ")" << '\n';

}

int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	startIdx = N;
	dfs(startIdx);

	return 0;
}
//0번index(출발)
//2번index(5시)
//4번index(8시)
//5번index(9시)