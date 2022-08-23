#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, cost;
};

bool cmp(Edge a, Edge b) {
    if (a.cost < b.cost) return true;
    if (a.cost > b.cost) return false;
    return true;
}

int parent[10001];
vector<Edge> v;
int ans = 0;

int Find(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa == pb)
        return;
    parent[pb] = pa;
}

void kruskal() {
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        Edge now = v[i];
        if (Find(now.a) == Find(now.b))
            continue;
        ans += now.cost;
        Union(now.a, now.b);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({ from, to, cost });
    }
    kruskal();
    cout << ans;
}