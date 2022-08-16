#include <iostream>
using namespace std;

int N, M;
int store[100001];

long long calcPeople(int time) {
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += time / store[i];
	}

	return sum;
}

void bs(int sp, int ep) {
	int last = -1;

	while (sp <= ep) {
		int mid = (sp + ep) / 2;
		long long can = calcPeople(mid);

		if (can < M) {
			sp = mid + 1;
		}
		else {
			last = mid;
			ep = mid - 1;
		}
	}

	cout << last;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> store[i];
	}

	bs(1, 11e8);
	return 0;
}