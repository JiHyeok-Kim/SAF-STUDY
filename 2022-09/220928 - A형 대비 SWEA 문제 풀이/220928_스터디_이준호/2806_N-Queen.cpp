#include <iostream>
using namespace std;

int queen[10];
int n;
int res;

bool isPossible(int row) {
    for (int i = 0; i < row; ++i) {
        if (queen[i] == queen[row]) return 0;

        if (abs(i - row) == abs(queen[i] - queen[row])) {
            return 0;
        }
    }
    return 1;
}

void dfs(int lev) {
    if (lev == n) {
        res++;
        return;
    }

    for (int i = 0; i < n; i++) {
        queen[lev] = i;
        if (isPossible(lev)) {
            dfs(lev + 1);
        }

    }
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> n;
        res = 0;
        dfs(0);

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}