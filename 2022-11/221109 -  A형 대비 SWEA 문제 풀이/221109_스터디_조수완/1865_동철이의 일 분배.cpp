#include <iostream>
#include <cstring>
using namespace std;
int T, N;
double arr[20][20], result;
double used[20];

void dfs(int lev, double per) {
    if (lev == N) {
        if (result < per * 100)result = per * 100;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (used[i] == 1)continue;
        if (arr[lev][i] == 0)continue;
        if (result != 0 && per * arr[lev][i] * 100 < result)continue;
        used[i] = 1;
        dfs(lev + 1, per * arr[lev][i]);
        used[i] = 0;
    }
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        result = 0;
        cin >> N;
        for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) { cin >> arr[y][x]; arr[y][x] /= 100; }
        dfs(0, 1);
        cout << "#" << t << " " << result << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    cout << fixed;
    cout.precision(6);
    solve();
    return 0;
}