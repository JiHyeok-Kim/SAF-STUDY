// 테네스의 특별한 소수
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int D, A, B, cnt, used[1000001];

void Eratosthenes() {
    for (int i = 2; i < 1000001; i++) {
        if (used[i] == 1) continue;
        for (int j = i * 2; j < 1000001; j += i) {
            used[j] = 1;
        }
    }
}

void favoriteNum() {
    string D_tmp = to_string(D);

    for (int i = A; i <= B; i++) { // search
        if (used[i] == 1) continue;
        string i_tmp = to_string(i);

        int tmp = i_tmp.find(D_tmp);

        if (tmp > -1) cnt++;
    }
}

void init() {
    D = 0;
    A = 0;
    B = 0;
    cnt = 0;
}

int main() {
    Eratosthenes();

    int T;
    cin >> T;

    used[0] = 1;
    used[1] = 1;

    for (int tc = 0; tc < T; tc++) {
        init();

        cin >> D >> A >> B;

        favoriteNum();

        cout << "#" << tc + 1 << " " << cnt << endl;
    }

    return 0;
}