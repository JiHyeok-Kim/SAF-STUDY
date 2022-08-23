#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct star {
	double y;
	double x;
};

struct connect {
	int a;
	int b;
	double energy;
};

bool cmp(connect A, connect B) {
	if (A.energy < B.energy) return true;
	if (A.energy > B.energy) return false;

	return false;
}

int n;

star arr[100];
vector<connect> v;
int parents[100];

int Find(int now) {
	if (parents[now] == now) return now;

	return parents[now] = Find(parents[now]);
}

void UNION(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	parents[pB] = pA;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i].y >> arr[i].x;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double e = sqrt(pow(arr[i].y - arr[j].y, 2) + pow(arr[i].x - arr[j].x, 2));
			v.push_back({ i,j,e });
		}
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	double result = 0;

	for (int i = 0; i < v.size(); i++) {
		if (Find(v[i].a) == Find(v[i].b)) continue;

		UNION(v[i].a, v[i].b);
		cnt++;
		result += v[i].energy;
		if (cnt == n - 1) break;
	}

	printf("%.2f", result);
	return 0;
}