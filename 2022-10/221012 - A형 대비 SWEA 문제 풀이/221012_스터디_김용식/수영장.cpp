#include <iostream>
#include <algorithm>
using namespace std;
 
int tc;
int Fee[4] = { 0 };
int Month[13] = { 0 };
int MonP[4] = { 1,1,3,12 };
int Min = 21e8;
 
void clear() {
 
    Min = 21e8;
 
    for (int i = 0; i < 4; i++) {
        Fee[i] = 0;
    }
 
    for (int i = 0; i < 13; i++) {
        Month[i] = 0;
    }
 
    return;
}
 
int calc(int month, int fee) {
    if (fee == 0) return Month[month] * Fee[fee];
    else return Fee[fee];
}
 
void input() {
     
    for (int i = 0; i < 4; i++) {
        cin >> Fee[i];
    }
 
    for (int i = 1; i <= 12; i++) {
        cin >> Month[i];
    }
 
    return;
}
 
 
void dfs(int month, int Sum) {
    if (month == 13) {
        Min = min(Min, Sum);
        return;
    }
 
    for (int i = 0; i < 4; i++) {
        if (month + MonP[i] > 13) continue;
        int ret = calc(month, i);
        dfs(month + MonP[i],Sum + ret );
    }
     
}
 
int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> tc;
     
    for (int TC = 1; TC <= tc; TC++) {
        input();
        dfs(1, 0);
        cout << "#" << TC << " " << Min << '\n';
        clear();
    }
     
 
 
 
 
 
    return 0;
}