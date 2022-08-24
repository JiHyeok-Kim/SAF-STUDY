#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pipe;
int Arr[1001] = {0};
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		pipe.push_back(temp);
	}
	
	//정렬

	sort(pipe.begin(), pipe.end());

	for (int i = 0; i < pipe.size(); i++) {
		Arr[pipe[i]]=1;
	}
	
	int cnt = 0;
	int a=0;
	while (a <= 1001) {
		if (Arr[a] == 1) {
			cnt++;
			a += m-1;
		}
		a++;
	}


	cout << cnt;
	return 0;
}