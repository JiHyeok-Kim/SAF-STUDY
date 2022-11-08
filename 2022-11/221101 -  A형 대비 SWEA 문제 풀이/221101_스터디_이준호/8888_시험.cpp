#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int N, T, P, ans1, ans2;
int map[2010][2010];
int munje[2010];
 
struct Node {
    int idx, score, count;
};
 
Node info[2010];
 
bool cmp(Node t, Node v) {
    if(t.score != v.score) return t.score > v.score;
    if(t.count != v.count) return t.count > v.count;
    return t.idx < v.idx;
}
 
 
void init() {
    ans1 = ans2 = 0;
    memset(map, 0, sizeof(map));
    memset(munje, 0, sizeof(munje));
    memset(info, 0, sizeof(info));
}
void input() {
    cin >> N >> T >> P;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < T; x++) {
            cin >> map[y][x];
            info[y].idx = y + 1;
            if (map[y][x] == 0) munje[x]++;
            else info[y].count++;
        }
    }
}
void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < T; x++) {
            if (map[y][x] == 1) {
                info[y].score += munje[x];
            }
        }
    }
    sort(info, info + N, cmp);
     
    for (int y = 0; y < N; y++) {
        if (info[y].idx == P) {
            ans1 = info[y].score;
            ans2 = y + 1;
            break;
        }
    }
 
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        init();
        input();
        solve();
        cout << "#" << tc << " " << ans1 << " " << ans2 << "\n";
    }
 
    return 0;
}