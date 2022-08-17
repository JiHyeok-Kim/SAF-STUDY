#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

int main() {
	int moy, d[] = { 500, 100, 50, 10 }, cnt = 0;
	cin >> moy;

	for (int i = 0; i < 4; i++) {
		cnt += moy / d[i];
		moy = moy % d[i];
	} cout << cnt << endl;

	return 0;
}