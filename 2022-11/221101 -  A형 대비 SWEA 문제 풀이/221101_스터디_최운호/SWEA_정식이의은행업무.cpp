#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string num[2];
int answer;
int flag = 0;

void init() {
    cin >> num[0] >> num[1];
    flag = 0;
}

bool check() {
    int size = num[0].size();
    int binSum = 0;
    for (int i = 0; i < size; i++) {
        int temp = pow(2, size - (i + 1)) * (num[0][i] - '0');
        binSum += temp;
    }
    size = num[1].size();
    int triSum = 0;
    for (int i = 0; i < size; i++) {
        int temp = pow(3, size - (i + 1)) * (num[1][i] - '0');
        triSum += temp;
    }
    if (binSum == triSum) {
        answer = binSum;
        return true;
    }

    return false;
}

void dfs(int lev) {
    if (flag) return;

    if (lev == 2) {
        if (check()) {
            flag = 1;
            return;
        }
    }
    int brn, ct, tt;
    ct = num[lev].size();
    brn = lev + 1;
    tt = lev + 2;
    for (int i = 0; i < ct; i++) {
        char prev = num[lev][i];
        int now = num[lev][i] - '0';
        for (int j = 0; j < brn; j++) {
            now = (now + 1) % tt;
            num[lev][i] = now + '0';
            dfs(lev + 1);
            num[lev][i] = prev;
        }
    }
}

void solve() {
    dfs(0);
}

int main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        init();

        solve();

        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}