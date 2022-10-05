#include <iostream>
#include <cstring>
using namespace std;
int arr[1100], N, result;
int memo[1100];
void input() {
    memset(arr, 0, sizeof(arr));
    memset(memo, 0, sizeof(memo));
    result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}
void solution() {
    memo[0] = 1;
    for (int i = 1; i < N; i++) {
        memo[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) continue;
            memo[i] = max(memo[j] + 1, memo[i]);
        }
        result = max(result, memo[i]);
    }
}
void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        solution();
        cout << "#" << t << " " << result << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}