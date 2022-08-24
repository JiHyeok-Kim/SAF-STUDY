#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[101];
int N;
struct Node {
    double x;
    double y;
};

struct Node_d {
    int  a;
    int  b;
    double d;
};

vector<Node> v;
double sumVal = 0;

bool compare(Node_d t,Node_d v)
{
    return t.d<v.d;
}

int Find(int now)
{
    if (parent[now] == now) return now;

    int root = Find(parent[now]);
    parent[now] = root;
    return root;
}

void Union(int A, int B)
{
    int pA = Find(A);
    int pB = Find(B);
    if (pA == pB)return;
    parent[pB] = pA;

}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        double x, y;
        cin >> x >> y;
        v.push_back({ x,y });
    }
    
    vector<Node_d>dis;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<v.size();j++)
        {
            double p = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
            dis.push_back({i,j,p});
        }
    }
    
    sort(dis.begin(),dis.end(),compare);
    
    for(int x = 0; x<dis.size(); x++)
    {
        if(Find(dis[x].a)==Find(dis[x].b))continue;
        
        sumVal+= dis[x].d;
        
        Union(dis[x].a,dis[x].b);
    }
        
    printf("%.2f",sumVal);
}