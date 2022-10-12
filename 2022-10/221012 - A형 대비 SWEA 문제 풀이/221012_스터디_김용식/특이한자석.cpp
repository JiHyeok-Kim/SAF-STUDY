#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
int Tc;
int Mag[4][8] = { 0 };
int K;
int boxa[8] = { 0 };
struct Node {
    int mag;
    int direc;
};
vector<Node> v;
 
 
void clear() {
    memset(Mag, 0, sizeof(Mag));
    v.clear();
    return;
}
 
void input() {
    cin >> K;
     
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> Mag[i][j];
        }
    }
 
    for (int i = 0; i < K; i++) {
        int mag, di;
        cin >> mag >> di;
        v.push_back({ mag,di });
    }
 
 
    return;
}
 
void right(int Ma, int Di) {
    int ret = 0;
    for (int i = Ma; i < 4; i++) {
        if (i + 1 >= 4)continue;
        if (Mag[i][2] == Mag[i + 1][6])break;
        ret++;
    }
 
    for (int i = Ma + 1; i < Ma + 1 + ret; i++) {
        if (Di == 1) {
            Di = -1;
            int temp = Mag[i][0];
            for (int j = 1; j < 8; j++) {
                Mag[i][j - 1] = Mag[i][j];
            }
            Mag[i][7] = temp;
        }
        else {
            Di = 1;
            int temp = Mag[i][7];
            for (int j = 0; j < 8; j++) {
                boxa[j] = Mag[i][j];
            }
            for (int j = 0; j < 7; j++) {
                Mag[i][j + 1] = boxa[j];
            }
            Mag[i][0] = temp;
        }
    }
 
    return;
}
 
void left(int Ma, int Di) {
    int ret = 0;
    for (int i = Ma; i >= 0; i--) {
        if ((i - 1) < 0)continue;
        if (Mag[i][6] == Mag[i - 1][2])break;
        ret++;
    }
 
    for (int i = Ma - 1 ; i > Ma -1 - ret; i--) {
        if (Di == 1) {
            Di = -1;
            int temp = Mag[i][0];
            for (int j = 1; j < 8; j++) {
                Mag[i][j - 1] = Mag[i][j];
            }
            Mag[i][7] = temp;
        }
        else {
            Di = 1;
            int temp = Mag[i][7];
            for (int j = 0; j < 8; j++) {
                boxa[j] = Mag[i][j];
            }
            for (int j = 0; j < 7; j++) {
                Mag[i][j + 1] = boxa[j];
            }
            Mag[i][0] = temp;
        }
    }
    return;
}
 
int solve() {
    int ans = 0;
 
    for (int i = 0; i < v.size(); i++) {
        right(v[i].mag-1, v[i].direc);
        left(v[i].mag-1, v[i].direc);
        if (v[i].direc == -1) {
            int temp = Mag[v[i].mag-1][0];
            for (int j = 1; j < 8; j++) {
                Mag[v[i].mag-1][j - 1] = Mag[v[i].mag-1][j];
            }
            Mag[v[i].mag-1][7] = temp;
        }
        else {
            int temp = Mag[v[i].mag-1][7];
            for (int j = 0; j < 8; j++) {
                boxa[j] = Mag[v[i].mag-1][j];
            }
            for (int j = 0; j < 7; j++) {
                Mag[v[i].mag-1][j + 1] = boxa[j];
            }
            Mag[v[i].mag-1][0] = temp;
        }
    }
    int A = 1;
    for (int i = 0; i < 4; i++) {
        if (Mag[i][0] == 1) {
            ans += A;
        }
        A = A * 2;
    }
 
    return ans;
}
 
 
int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        input();
        int ret = solve();
        cout << "#" << tc << " " << ret << '\n';
        clear();
    }
 
 
    return 0;
}