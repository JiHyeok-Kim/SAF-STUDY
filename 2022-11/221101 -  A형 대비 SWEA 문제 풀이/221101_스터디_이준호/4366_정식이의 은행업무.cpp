#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
long long money1, money2, ans;
long long temp, temp2, diff;
string num1, num2;
 
bool isRight(int diff) {
    if (diff == 1) {
        if (num1[num1.size() - 1] == '0') {
            ans = money1 + 1;
            return 1;
        }
    }
    else if (diff == -1) {
        if (num1[num1.size() - 1] == '1') {
            ans = money1 - 1;
            return 1;
        }
    }
    return 0;
}
 
 
void solve() {
    for (int i = num1.size() - 1; i >= 0; i--) {
        money1 += (num1[i] - '0') * pow(2, num1.size() - 1 - i);
    }
    for (int i = num2.size() - 1; i >= 0; i--) {
        money2 += (num2[i] - '0') * pow(3, num2.size() - 1 - i);
    }
     
    int tar;
    for (int i = num2.size() - 1; i >= 0; i--) {
        tar = num2[i] - '0';
        temp = tar * pow(3, num2.size() - 1 - i);
 
        money2 -= temp;
        for (int k = 0; k <= 2; k++) {
            if (k == tar) continue;
            temp2 = k * pow(3, num2.size() - 1 - i);
             
            money2 += temp2;
            diff = money2 - money1;
            // diff가 1 or -1
            if (diff == 1 || diff == -1) {
                if(isRight(diff) == 1) return;
            }
            // 홀수면 건너뛰기
            if (abs(diff) % 2 == 1) {
                money2 -= temp2;
                continue;
            }
            // 2의 제곱인지 확인
            int cnt = 1;
            int flag = 0;
            while (1) {
                if (cnt >= num1.size()) break;
                if (abs(diff) == pow(2, cnt)) { flag = 1; break; }
                if (abs(diff) < pow(2, cnt)) { flag = 0; break; }
                cnt++;
            }
            if (flag == 1) {
                int idx = num1.size() - cnt - 1;
                // diff 가 음수
                if (diff < 0 && num1[idx] == '1') {
                    ans = money2;
                    return;
                }
                // diff 가 양수
                else if (diff > 0 && num1[idx] == '0') {
                    ans = money2;
                    return;
                }
            }
            money2 -= temp2;
        }
        money2 += temp;
    }
 
    return;
}
     
 
 
int main()
{
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> num1 >> num2;
        money1 = money2 = ans = 0;
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
 
    return 0;
}