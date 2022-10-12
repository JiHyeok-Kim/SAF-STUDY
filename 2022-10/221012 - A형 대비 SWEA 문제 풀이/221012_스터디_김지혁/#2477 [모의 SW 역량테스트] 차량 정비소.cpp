#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Desk {
    int time;
    int next;
    int full;
    vector<int> idx;
};

struct Node {
    int idx;
    int time;
};

int N, M, K, A, B, ans;
vector<Desk> deskA;
vector<Desk> deskB;
queue<Node> q;
queue<Node> waitA;
queue<Node> waitB;

void init()
{
    cin >> N >> M >> K >> A >> B;
    ans = 0;
    deskA.clear();
    deskB.clear();
    deskA.push_back({ -1, -1, -1, {0} });
    deskB.push_back({ -1, -1, -1, {0} });

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        deskA.push_back({ n, -1, 0, {0} });
    }
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        deskB.push_back({ n, -1, 0, {0} });
    }
    for (int i = 1; i <= K; i++) {
        int n;
        cin >> n;
        q.push({ i, n });
    }

    return;
}

void helloDeskA(int t, Node cstm, int flag)
{
    int n = waitA.size();
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            Node wait = waitA.front();
            for (int a = 1; a <= N; a++) {
                if (deskA[a].full == 0) {
                    deskA[a].full = wait.idx;
                    deskA[a].idx.push_back(wait.idx);
                    deskA[a].next = t + deskA[a].time;
                    waitA.pop();
                    break;
                }
            }
        }
    }

    if (flag == 1) {
        int full = 1;
        for (int a = 1; a <= N; a++) {
            if (deskA[a].full == 0) {
                deskA[a].full = cstm.idx;
                deskA[a].idx.push_back(cstm.idx);
                deskA[a].next = t + deskA[a].time;
                full = 0;
                break;
            }
        }
        if (full == 1) {
            if (cstm.time == t) waitA.push(cstm);
        }
    }

    return;
}

void byeDeskA(int t)
{
    int n = waitB.size();
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            Node wait = waitB.front();
            for (int b = 1; b <= M; b++) {
                if (deskB[b].full == 0) {
                    deskB[b].full = wait.idx;
                    deskB[b].idx.push_back(wait.idx);
                    deskB[b].next = t + deskB[b].time;
                    waitB.pop();
                    break;
                }
            }
        }
    }

    for (int a = 1; a <= N; a++) {
        if (deskA[a].next == t) {
            for (int b = 1; b <= M; b++) {
                if (deskB[b].full == 0) {
                    deskB[b].full = deskA[a].full;
                    deskB[b].idx.push_back(deskA[a].full);
                    deskA[a].full = 0;
                    deskA[a].next = -1;
                    deskB[b].next = t + deskB[b].time;
                    break;
                }
            }
        }
    }

    for (int a = 1; a <= N; a++) {
        if (deskA[a].next == t) {
            waitB.push({ deskA[a].full, 0 });
            deskA[a].full = 0;
            deskA[a].next = -1;
        }
    }

    return;
}

int isEnd()
{
    if (q.empty() && waitA.empty() && waitB.empty()) {
        int sum = 0;
        for (int a = 1; a <= N; a++) {
            if (deskA[a].full > 0) {
                sum++;
            }
        }
        if (sum == 0) return 0;
    }

    return 1;
}


void byeDeskB(int t)
{
    for (int b = 1; b <= M; b++) {
        if (deskB[b].next == t) {
            deskB[b].full = 0;
            deskB[b].next = -1;
        }
    }

    return;
}

void goShop()
{
    int flag;
    int t = -1;
    int finish = 1;
    while (finish)
    {
        flag = 0;

        Node cstm;
        if (!q.empty()) {
            cstm = q.front();
            if (cstm.time != t) t++;
            if (cstm.time == t) {
                flag = 1;
                q.pop();
            }
        }
        else {
            cstm = { -1, -1 };
            t++;
        }

        byeDeskB(t);
        byeDeskA(t);
        helloDeskA(t, cstm, flag);

        finish = isEnd();
    }

    return;
}

int check()
{
    int sum = 0;
    if (deskA[A].idx.size() > 1) {
        int flag = 0;
        if (deskB[B].idx.size() > 1) {
            for (auto& b : deskB[B].idx) {
                for (auto& a : deskA[A].idx) {
                    if (a == b) {
                        flag = 1;
                        sum += a;
                    }
                }
            }
        }

        if (flag == 1 && sum != 0) return sum;
    }

    return -1;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();

        goShop();
        ans = check();
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}