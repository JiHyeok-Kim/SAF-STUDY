#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int cnt[150];
char cnt_char[150];
int counter;
typedef struct {
	char left = '#';
	char right = '#';
}NODE;
vector <vector<NODE>> v(150);

string strs[1001];
bool compare(string t, string v) {
	int len = 0;
	int size_t = t.size();
	int size_v = v.size();

	if (size_t < size_v) len = size_t;
	else len = size_v;

	for (int i = 0; i < len; ++i) {
		if (t[i] < v[i]) return 1;
		if (t[i] > v[i]) return 0;
	}

	if (size_t < size_v) return 1;
	if (size_t > size_v) return 0;
}

void DFS(char node) {
	cnt[node] = ++counter;
	if (v[node][0].left != '#') DFS(v[node][0].left);
	if (v[node][0].right != '#') DFS(v[node][0].right);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		char num;
		NODE target;
		cin >> num >> target.left >> target.right;
		v[num].push_back(target);
	}
	
	// root node 구하기 -> check_root[]
	char init_c;
	int check_root[150] = { 0, };
	for (int i = 0; i < 150; ++i) {
		if (v[i].size() == 0) continue;
		check_root[i]++;
		check_root[v[i][0].left]++;
		check_root[v[i][0].right]++;
	}

	for (int i = 0; i < 150; ++i) {
		if (check_root[i] == 1) {
			init_c = i;
			break;
		}
	}

	// 우선순위 부여 -> cnt[]
	DFS(init_c);
	
	// 정렬
	int comp_N;
	cin >> comp_N;
	for (int i = 0; i < comp_N; ++i) {
		cin >> strs[i];
		for (int j = 0; j < strs[i].size(); ++j) {
			strs[i][j] = cnt[strs[i][j]] + 48;
		}
	}

	sort(strs, strs + comp_N, compare);
	for (int i = 0; i < 150; ++i) {
		if (cnt[i] == 0) continue;
		cnt_char[cnt[i]] = i;
	}

	for (int i = 0; i < comp_N; ++i) {
		for (int j = 0; j < strs[i].size(); ++j) {
			strs[i][j] = cnt_char[strs[i][j] - 48];
		}
	}
	for (int i = 0; i < comp_N; ++i) {
		cout << strs[i] << "\n";
	}

	return 0;
}