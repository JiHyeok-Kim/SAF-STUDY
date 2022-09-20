#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;
int maxi, maxcnt;
int path[15][10];
int tempMax, flag = 0;
void init() {
    flag = 0;
    maxi = -1;
}
void input() {
    cin >> num >> maxcnt;
    string temp = num;
    sort(temp.begin(), temp.end(), greater<char>());
    tempMax = stoi(temp);
    int a = 1;
}
void sol(int lev, int start, int cnt, string temp) {
    if (lev == 2 && cnt == maxcnt - 1) {
        swap(temp[path[cnt][0]], temp[path[cnt][1]]);
        maxi = max(maxi, stoi(temp));
        if (maxi == tempMax) flag = 1;
        return;
    }
    if (lev == 2) {
        swap(temp[path[cnt][0]], temp[path[cnt][1]]);
        int temp1 = stoi(temp);
        if (temp1 == tempMax) {
            if ((maxcnt - cnt - 1) % 2 == 1) {
                swap(temp[temp.length() - 2], temp[temp.length() - 1]);
                maxi = stoi(temp);
            }
            else maxi = temp1;
            flag = 1;
        }
        if (flag == 1) return;
        sol(0, 0, cnt + 1, temp);
        return;
    }
    for (int i = start; i < num.length(); i++) {
        path[cnt][lev] = i;
        sol(lev + 1, i + 1, cnt, temp);
        if (flag == 1) return;
    }
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        sol(0, 0, 0, num);
        cout << "#" << t << " " << maxi << "\n";
    }
    return 0;
}