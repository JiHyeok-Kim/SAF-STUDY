#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <int> v;

int returnNum(int len) {
	int sum = 0;

	for (int i = 0; i < v.size(); ++i) {
		sum += v[i] / len;
	}

	return sum;
}

void binarySearch(int start, int end) {
	int last = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		int ret_num = returnNum(mid);

		if (ret_num < K) {
			//last = mid;
			end = mid - 1;
		}
		else {
			last = mid;
			start = mid + 1;
		}
		
	}

	cout << last;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int target;
		cin >> target;
		v.push_back(target);
	}

	binarySearch(1, 21e7);
	return 0;
}