//별자리가 만드는 최소 에너지;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	double y, x;
};
struct Real {
	int y, x;
	double distance;
};
vector<Node> list;
vector<Real> dist;

int parent[150];

bool compare(Real t, Real v) {
	if (t.distance < v.distance)return true;
	if (t.distance > v.distance)return false;
	
	return false;
}


int Find(int now) {
	if (parent[now] == now)return now;
	return parent[now] = Find(parent[now]);
}


void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	parent[pB] = pA;
}



int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;

	for (int i = 0; i < 150; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		double a, b;
		cin >> a >> b;
		list.push_back({ a,b });
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			double dist2 = (list[i].y - list[j].y) * (list[i].y - list[j].y) + (list[i].x - list[j].x) * (list[i].x - list[j].x);
			double Dist =sqrt(dist2);
			dist.push_back({ i,j,Dist });
		}
	}
	
	sort(dist.begin(), dist.end(), compare);

	double sum = 0;
	int cnt = 0;
	for (int i = 0; i <dist.size(); i++) {
		if (Find(dist[i].x) == Find(dist[i].y))continue;
		Union(dist[i].y, dist[i].x);
		sum += dist[i].distance;
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;

	return 0;
}