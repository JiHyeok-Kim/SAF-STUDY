#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
vector<int> v;

void solve() {
	cin >> T;for(int t=1;t<=T;t++){
		cin >> N; int r = 0; v.clear();
		for (int i = 0; i < N; i++) {
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		while (v.size() > 0) {
			int a = 50 / v.back();
			if (50 % v.back() == 0)a--;
			int s = v.back();
			v.erase(v.begin() + v.size() - 1);
			int c = 1;
			for (int i = 0; i < a; i++) {
				if (v.size() == 0)break;
				v.erase(v.begin());
				c++;
			}
			if (s * c >= 50)r++;
		}
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}