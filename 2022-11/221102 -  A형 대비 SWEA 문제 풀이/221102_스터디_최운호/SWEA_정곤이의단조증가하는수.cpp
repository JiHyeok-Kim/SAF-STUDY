#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int nums[1000];
vector<int> v;

bool check(int tar)
{
	string str = to_string(tar);

	int len = str.size();

	for (int i = 0; i < len - 1; i++) {
		int front = str[i] - '0';
		int back = str[i + 1] - '0';
		if (front > back) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> nums[i];

		for (int i = 0; i < N - 1; i++) {
			if (nums[i] % 10 == 0) continue;
			for (int j = i + 1; j < N; j++) {
				if (nums[j] % 10 == 0) continue;
				int tmp = nums[i] * nums[j];
				if (check(tmp)) v.push_back(tmp);
			}
		}

		if (v.size() == 0) {
			cout << "#" << t << " -1" << '\n';
			continue;
		}

		sort(v.begin(), v.end(), greater<>());
		cout << "#" << t << " " << v[0] << '\n';
		v.clear();
	}

	return 0;
}