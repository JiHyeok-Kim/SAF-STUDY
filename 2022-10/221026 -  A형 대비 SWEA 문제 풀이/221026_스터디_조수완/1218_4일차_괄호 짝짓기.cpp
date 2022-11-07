#include <iostream>
#include <string>
using namespace std;
int N, result;
string str;

void solve() {
    for (int t = 1; t <= 10; t++) {
        result = 1;
        cin >> N >> str;
        int dat[1000] = { 0 };
        for (int i = 0; i < N; i++) dat[str[i]]++;
        if (dat['<'] != dat['>'])result = 0;
        if (dat['('] != dat[')'])result = 0;
        if (dat['{'] != dat['}'])result = 0;
        if (dat['['] != dat[']'])result = 0;
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