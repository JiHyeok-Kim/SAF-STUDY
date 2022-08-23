#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char univ[1000];
int parent[1000];
typedef struct {
	int cur, next;
	int cost;
}CON;
vector <CON> v;

bool compare(CON t, CON v) {
	return t.cost < v.cost;
}

int Find(int tar) {
	if (parent[tar] == 0) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> univ[i];
	}
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ --a,--b,c });
	}
	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int ret = 0;
	int flag = 0;
	for (int i = 0; i < v.size(); ++i) {
		CON target = v[i];
		// todo something...
		if (univ[target.cur] == univ[target.next]) continue;
		if (Find(target.cur) == Find(target.next)) continue;
		//
		Union(target.cur, target.next);
		cnt++;
		ret += target.cost;
		if (cnt == N - 1) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) ret = -1;
	cout << ret;
	return 0;
}