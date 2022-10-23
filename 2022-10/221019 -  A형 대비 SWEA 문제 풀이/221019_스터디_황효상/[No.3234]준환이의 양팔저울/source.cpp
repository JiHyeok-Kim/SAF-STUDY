#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T, N;
double nums[10];
bool used[10];
double mid = 0;
int ans = 0;

int fac(int num) {
    int start = 2;
    int idx = 2;
    while (idx <= num) {
        start = start * idx*2;
        ++idx;
    }
    return start;
}
void dfs(double left, double right, int deep) {
    if (deep == N) {
        ++ans;
        return;
    }

    if (left >= mid) {
        ans = ans + fac(N - deep);
        return;
    }
    for (int a = 0; a < N; ++a) {
        if (used[a] == 0) {
            double duhagi = right + nums[a];
            used[a] = 1;
            if ((left >= duhagi) && duhagi <= mid) {
                dfs(left, duhagi, deep + 1);
            }
            dfs(left + nums[a], right, deep + 1);
            used[a] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("Input.txt", "r", stdin);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        ans = 0;
        double tmp = 0;
        for (int a = 0; a < N; ++a) {
            cin >> nums[a];
            tmp += nums[a];
        }
        mid = tmp / 2;
        for (int a = 0; a < N; ++a) {
            used[a] = 1;
            dfs(nums[a], 0, 1);
            used[a] = 0;
        }
        cout << "#" << t << " " << ans << "\n";
    }


    return 0;
}
