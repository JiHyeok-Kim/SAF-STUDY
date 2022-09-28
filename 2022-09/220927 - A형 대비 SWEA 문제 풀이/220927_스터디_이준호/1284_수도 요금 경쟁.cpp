#include <iostream>
using namespace std;

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    int p, q, r, s, w;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> p >> q >> r >> s >> w;

        int A = p * w;
        int B;
        if (w <= r) B = q;
        else B = q + (w - r) * s;

        int ans = min(A, B);

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}