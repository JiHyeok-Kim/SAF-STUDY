#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;


struct Node {
	int idx;
	int grade;
};

bool compare(Node a, Node b) {
	return a.grade > b.grade;
}
vector<Node> v;
int N, K;
string grade[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
void print(int idx,int t) {
	double one_step = N / 10;

	for (int a = 1; a <= 10; ++a) {
		if (one_step*a >= idx) {
			cout << "#"<<t<<" " <<grade[a - 1] << "\n";
			return;
		}
	}
}
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		v.clear();
		cin >> N >> K;
		for (int a = 0; a < N; ++a) {
			int joong, gi, gwa;
			cin >> joong >> gi >> gwa;
			joong = joong *35;
			gi = gi *45;
			gwa = gwa *20;
			v.push_back({ a+1,joong + gi + gwa });
		}
		sort(v.begin(), v.end(), compare);
		
		for (int a = 0; a < N; ++a) {
			if (v[a].idx == K) {
				print(a+1,t);
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
