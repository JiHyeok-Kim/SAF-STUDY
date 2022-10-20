#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;
 
int sosu[1001];
vector<int> nums;
int T;
int N;
int ans;
int bs(int num) {
    int s = 0;
    int e = nums.size() - 1;
    int target = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (nums[mid] > num) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
            target = mid;
        }
    }
 
    return target;
             
}
 
void dfs(int deep, int sum,int idx) {
    for (int a = idx; a >= 0; --a) {
        int target = nums[a] + sum;
        if (deep < 2) {
            if (target >= N)
                continue;
            else
                dfs(deep + 1, target,a);
        }
        else {
            if (target == N) {
                ++ans;
            }
        }
    }
}
void prim() {
    for (register unsigned int a = 2; a <= 1000; ++a) {
        if (sosu[a] == 0) {
            nums.push_back(a);
            for (register unsigned int b = a+a; b <= 1000; b+=a) {
                if (sosu[b] == 0)
                    sosu[b] = 1;
            }
        }
    }
 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("Input.txt", "r", stdin);
    prim();
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        int size = nums.size() - 1;
        int start = bs(N);
        for (int a = start; a >= 0; --a) {
            dfs(1, nums[a],a);
        }
        cout << "#"<<t<<" " <<ans << "\n";
        ans = 0;
    }
    return 0;
}
