// SWEA 무선충전
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int T, M, A;
int MAP[10][10];
int dat[8][10][10];
int ret;
 
vector<int> v[2];
typedef struct {
    int y, x;
    int dist;
    int power;
}POSI;
vector<POSI> phone;
queue<POSI> q;
vector<int> pick1, pick2;
 
const int dy[] = { 0,-1,0,1,0 };
const int dx[] = { 0,0,1,0,-1 };
 
void makeArea(POSI target, int number) {
    bool visited[10][10];
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            visited[y][x] = false;
        }
    }
 
    q.push(target);
    while (!q.empty()) {
        POSI cur = q.front();   q.pop();
        visited[cur.y][cur.x] = true;
        dat[number][cur.y][cur.x] = 1;
        if (cur.dist == 0) break;
 
        for (int dir = 1; dir <= 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10) continue;
            if (visited[ny][nx] == true) continue;
 
            dat[number][ny][nx] = 1;
            visited[ny][nx] = true;
            q.push({ ny,nx,cur.dist - 1 });
        }
    }
 
    while (!q.empty()) q.pop();
}
 
int getMaxInThisPosition(int p1y, int p1x, int p2y, int p2x) {
    int cnt[8];
    for (int i = 0; i < A; ++i) {
        cnt[i] = 0;
    }
 
    pick1.clear(); pick2.clear();
    for (int phone = 0; phone < A; ++phone) {
        if (dat[phone][p1y][p1x] == 1) cnt[phone]++;
    }
    for (int i = 0; i < A; ++i) {
        if (cnt[i] > 0) pick1.push_back(i);
    }
 
    for (int i = 0; i < A; ++i) {
        cnt[i] = 0;
    }
 
    for (int phone = 0; phone < A; ++phone) {
        if (dat[phone][p2y][p2x] == 1) cnt[phone]++;
    }
    for (int i = 0; i < A; ++i) {
        if (cnt[i] > 0) pick2.push_back(i);
    }
     
    int sum = 0;
    if (pick1.size() == 0) {
        if (pick2.size() == 0) return 0;
        else {
            for (int i = 0; i < pick2.size(); ++i) {
                if (sum < phone[pick2[i]].power) {
                    sum = phone[pick2[i]].power;
                }
            }
            return sum;
        }
    }
    if (pick2.size() == 0) {
        if (pick1.size() == 0) return 0;
        else {
            for (int i = 0; i < pick1.size(); ++i) {
                if (sum < phone[pick1[i]].power) {
                    sum = phone[pick1[i]].power;
                }
            }
            return sum;
        }
    }
     
    for (int i = 0; i < pick1.size(); ++i) {
        int one = pick1[i];
        for (int j = 0; j < pick2.size(); ++j) {
            int sub = 0;
            int two = pick2[j];
            if (one == two) sub = phone[one].power;
            else sub = phone[one].power + phone[two].power;
 
            if (sum < sub) sum = sub;
        }
    }
 
    return sum;
}
 
void Solve() {
    // 스마트 폰 반경 설정(MAP) -> q사용
    for (int i = 0; i < phone.size(); ++i) {
        makeArea(phone[i], i);
    }
    // 사람 이동(v[0], v[1]) 및 값 누적
    int len = v[0].size();
    int p1y = 0, p1x = 0, p2y = 9, p2x = 9;
    for (int i = 0; i < len; ++i) {
        p1y += dy[v[0][i]];
        p1x += dx[v[0][i]];
        p2y += dy[v[1][i]];
        p2x += dx[v[1][i]];
 
        int point = getMaxInThisPosition(p1y, p1x, p2y, p2x);
        ret += point;
    }
}
 
void init() {
    ret = 0;
    phone.clear();
    for (int i = 0; i < 2; ++i) {
        v[i].clear();
    }
 
    for (int i = 0; i < A; ++i) {
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                dat[i][y][x] = 0;
            }
        }
    }
}
 
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> M >> A;
        init();
        for (int pers = 0; pers < 2; ++pers) {
            v[pers].push_back(0);
            for (int i = 0; i < M; ++i) {
                int direct;
                cin >> direct;
                v[pers].push_back(direct);
            }
        }
 
        for (int i = 0; i < A; ++i) {
            int tx, ty, C, P;
            cin >> tx >> ty >> C >> P;
            phone.push_back({ --ty,--tx,C,P });
        }
 
        Solve();
        cout << "#" << tc << " " << ret << "\n";
    }
    return 0;
}