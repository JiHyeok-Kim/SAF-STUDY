#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[3001];
int V, E;

struct Node {
	int x; 
	int	y;
	int cost;
};

vector<Node>v;
int sumVal = 0;


bool compare(Node t, Node v)
{
	return t.cost < v.cost;
}

int Find(int now)
{
 	if (parent[now] == now)return now;

	int root = Find(parent[now]);
	return root;
}

void Union(int A, int B, int C)
{
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return;
	parent[pB] = pA;
	sumVal += C;
	
}

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		v.push_back({ from,to,cost });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < v.size(); i++)
	{
		Union(v[i].x, v[i].y,v[i].cost);
	}
	
	cout << sumVal;
}