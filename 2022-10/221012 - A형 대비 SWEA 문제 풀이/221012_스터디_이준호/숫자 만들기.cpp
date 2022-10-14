#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int map[12];
int op[12];
int maxi, mini;

void init() {
    ans = 0;
    maxi = -21e8;
    mini = 21e8;
    for (int i = 0; i < 12; i++) {
        map[i] = 0;
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
}


void run(int lev, int sum) {
    if (lev == n - 1) {
        if (maxi < sum) maxi = sum;
        if (mini > sum) mini = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;
        op[i]--;
        if (i == 0) run(lev + 1, sum + map[lev + 1]);
        else if (i == 1) run(lev + 1, sum - map[lev + 1]);
        else if (i == 2) run(lev + 1, sum * map[lev + 1]);
        else if (i == 3) run(lev + 1, sum / map[lev + 1]);
        op[i]++;
    }
}

int main()
{
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        init();
        input();

        run(0, map[0]);
        ans = maxi - mini;

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}