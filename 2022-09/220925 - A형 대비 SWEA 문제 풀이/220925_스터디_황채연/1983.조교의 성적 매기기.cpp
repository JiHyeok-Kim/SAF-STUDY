#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, K;
char sMAP[10][5] = {
	"A+",
	"A0",
	"A-",
	"B+",
	"B0",
	"B-",
	"C+",
	"C0",
	"C-",
	"D0"
};

typedef struct {
	int num;
	int score;
}STUDENT;
vector<STUDENT> v;

bool compare(STUDENT t, STUDENT v) {
	return t.score > v.score;
}

int Solve() {
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].num == K) {
			return i;
		}
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		v.clear();
		for (int i = 0; i < N; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ i + 1, a * 35 + b * 45 + c * 20 });
		}

		int idx = Solve();
		int oper = v.size() / 10;
		cout << "#" << tc << " " << sMAP[idx / oper] << "\n";
	}
	return 0;
}