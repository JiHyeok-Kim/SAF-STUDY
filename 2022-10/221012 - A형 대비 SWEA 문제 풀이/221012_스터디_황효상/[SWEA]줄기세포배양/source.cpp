#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include <map>
using namespace std;
 
struct Node {
    int x;
    int y;
    int timer;
    int cost;
    int in_time;
};
 
struct Cell {
    int x;
    int y;
};
bool operator<(Node a, Node b) {
    if (a.in_time < b.in_time) return 0;
    if (a.in_time > b.in_time) return 1;
 
    if (a.cost < b.cost) return 1;
    if (a.cost > b.cost) return 0;
 
    return 0;
}
 
 
int T, N, M, K;
priority_queue<Node> que;
int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool checker[800][800] = { 0 };
 
void bfs() {
 
    int timee = 0;
 
 
 
    while (timee != K) {
        int size = que.size();
 
        for (int a = 0; a < size; ++a) {
            int x = que.top().x;
            int y = que.top().y;
            int timer = que.top().timer;
            int cost = que.top().cost;
            que.pop();
 
            if (timer == 0) {
                if (cost != 1) {
                    que.push({ x,y,cost-2,1,timee });
                }
                for (int b = 0; b < 4; ++b) {
                    int xx = x + mov[b][0];
                    int yy = y + mov[b][1];
 
                    if (checker[xx][yy] == 1) continue;
                    checker[xx][yy] = 1;
                    que.push({ xx,yy,cost,cost,timee});
                }
            }
            else {
                que.push({ x,y,timer - 1,cost,timee});
            }
        }
        ++timee;
    }
 
}
void input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        cin >> N >> M >> K;
 
        for (int b = 0; b < N; ++b) {
            for (int c = 0; c < M; ++c) {
                int  cost;
                cin >> cost;
                if (cost != 0) {
                    checker[400 + b][400 + c] = 1;
                    que.push({ 400 + b,400 + c,cost,cost,-1 });
                }
            }
        }
        bfs();
 
        cout << "#"<<a+1 << " " <<que.size() << "\n";
 
        while (!que.empty())
            que.pop();
 
        for (int a = 0; a < 800; ++a) {
            for (int b = 0; b < 800; ++b) {
                checker[a][b] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
 
    cin.tie(NULL);
    cout.tie(NULL);
    input();
 
    return 0;
 
}
