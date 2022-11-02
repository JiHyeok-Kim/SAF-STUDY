#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int num;
    int probs;
    int score;
};

bool cmp(Node A, Node B) {
    if (A.score > B.score) return true;
    if (A.score < B.score) return false;

    if (A.probs > B.probs) return true;
    if (A.probs < B.probs) return false;

    if (A.num < B.num) return true;
    if (A.num > B.num) return false;
}

int N, T, P;
int score[2001];
Node getScore[2001];
vector<int> isSolve[2001];

void init() {
    cin >> N >> T >> P;
    for (int i = 1; i <= N; i++) {
        isSolve[i].clear();
        getScore[i - 1] = { 0,0,0 };
        for (int j = 0; j < T; j++) {
            score[j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < T; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 0) score[j]++;
            else if (tmp == 1) isSolve[i].push_back(j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();

        for (int i = 1; i <= N; i++) {
            int sum = 0;
            int len = isSolve[i].size();
            for (int loop : isSolve[i]) sum += score[loop];
            getScore[i - 1] = { i, len, sum };
        }

        sort(getScore, getScore + N, cmp);

        for (int i = 0; i < N; i++) {
            if (getScore[i].num == P) {
                cout << "#" << t << " " << getScore[i].score << " " << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}