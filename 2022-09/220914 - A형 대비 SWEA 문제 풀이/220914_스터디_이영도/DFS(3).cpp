// 크리스마스 트리
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
	int L;
	int R;
};
vector<vector<node>> vec(1001);

void dfs1(int now){
	if (vec[now][0].L != -1) dfs1(vec[now][0].L);
	cout << now << " ";
	if (vec[now][0].R != -1) dfs1(vec[now][0].R);
}
void dfs2(int now) {
	cout << now << " ";
	if (vec[now][0].L != -1) dfs2(vec[now][0].L);
	if (vec[now][0].R != -1) dfs2(vec[now][0].R);
}
void dfs3(int now) {
	if (vec[now][0].L != -1) dfs3(vec[now][0].L);
	if (vec[now][0].R != -1) dfs3(vec[now][0].R);
	cout << now << " ";
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) { // vector 초기화 
		int tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		vec[tmp1].push_back({ tmp2, tmp3 });
	}

	dfs1(1);
	cout << endl;
	dfs2(1);
	cout << endl; 
	dfs3(1);
	cout << endl;

	return 0;
}