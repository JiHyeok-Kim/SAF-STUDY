#include <iostream>
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    int ans;
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        int stu[1100] = { 0 };
        int dat[110] = { 0 };
        cin >> n;
 
        for (int i = 0; i < 1000; i++) {
            cin >> stu[i];
            dat[stu[i]]++;
        }
 
        int mode = 0;
        for (int i = 0; i < 100; i++) {
            if (mode <= dat[i]) {
                mode = dat[i];
                ans = i;
            }
        }
 
        cout << "#" << n << " " << ans << "\n";
    }
 
    return 0;
}