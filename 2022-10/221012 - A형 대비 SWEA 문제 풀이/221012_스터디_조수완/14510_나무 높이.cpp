#include <iostream>
using namespace std;
int N, maxiLen;
int tree[110];
void input() {
    maxiLen = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (tree[i] > maxiLen) maxiLen = tree[i];
    }
}
void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        int oddCnt = 0, evenCnt = 0;
        for (int i = 0; i < N; i++) {
            int temp = maxiLen - tree[i];
            evenCnt += temp / 2;
            oddCnt += temp % 2;
        }
        int result = max(2 * evenCnt, 2 * oddCnt - 1);
        while (1) {
            evenCnt--;
            oddCnt += 2;
            int temp = max(2 * evenCnt, 2 * oddCnt - 1);
            if (result < temp) break;
            result = temp;
        }
        cout << "#" << t << " " << result << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}