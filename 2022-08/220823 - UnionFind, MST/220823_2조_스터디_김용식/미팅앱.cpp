#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> app;

struct Node {
	int from, to, distance;
};

vector<Node> ap;
int parent[1000];

bool compare(Node t, Node v) {
	if (t.distance < v.distance)return true;
	if (t.distance > v.distance)return false;
	return false;
}

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}


void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	parent[pB] = pA;
}


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N,M;
	cin >> N>>M;

	for (int i = 0; i < 1000; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		char A;
		cin >> A;
		if (A == 'M') {
			app.push_back(1);
		}
		else if(A == 'W') {
			app.push_back(2);
		}
	}
	for (int i = 0; i < M; i++) {
		int from, to, distance;
		cin >> from >> to >> distance;
		ap.push_back({ from,to,distance });
	}
	sort(ap.begin(), ap.end(), compare);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < ap.size(); i++) {
		int from = ap[i].from;
		int to = ap[i].to;
		if (app[from - 1] == app[to - 1])continue;
		if (Find(from) == Find(to))continue;
		cnt++;
		Union(from, to);
		sum += ap[i].distance;

	
	}
	if (cnt < N-1){
		cout << -1;
		return 0;
	}
	cout << sum;
	int a = 2;


	return 0;
}