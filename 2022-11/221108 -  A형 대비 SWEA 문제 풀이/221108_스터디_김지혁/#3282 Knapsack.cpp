#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int vol, val;
};

int N, K, ans;
Node arr[100];
int dp[100][1001];

void init()
{
    ans = 0;
    memset(dp, 0, sizeof(dp));
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].vol >> arr[i].val;
    }

    return;
}

void solve()
{
    for (int i = 0; i <= K; i++) {
        if (i < arr[0].vol) continue;
        dp[0][i] = arr[0].val;
    }
    for (int y = 1; y < N; y++) {
        for (int x = 0; x <= K; x++) {
            if (x < arr[y].vol) dp[y][x] = dp[y - 1][x];
            else {
                int cmp = arr[y].val + dp[y - 1][x - arr[y].vol];
                dp[y][x] = max(cmp, dp[y - 1][x]);
            }
        }
    }

    ans = dp[N - 1][K];
    return;
}

int main()
{
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}