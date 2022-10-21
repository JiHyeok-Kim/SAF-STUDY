#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int sosu[1000001];
vector<int> nums;
int T;
char D;
int A, B;
int bs1(int num) {
    int s = 0;
    int e = nums.size() - 1;
    int target = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (nums[mid] >= num) {
            target = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return target;
            
}
int bs2(int num) {
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
void prim() {
    for (register unsigned int a = 2; a <= 1000000; ++a) {
        if (sosu[a] == 0) {
            nums.push_back(a);
            for (register unsigned int b = a+a; b <= 1000000; b+=a) {
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
   // freopen("Input.txt", "r", stdin);
    prim();
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> D >> A >> B;
        int start = bs1(A);
        int end = bs2(B);
        int ans = 0;
       for (int a = start; a <= end; ++a) {

            if (nums[a] > B)
                break;
            string tmp = to_string(nums[a]);
            for (int b = 0; b < tmp.length(); ++b) {
                if (tmp[b] == D) {
                    ++ans;
                    break;
                }
            }

        }
        cout << "#"<<t<<" "<<ans << "\n";
    }
    return 0;
}
