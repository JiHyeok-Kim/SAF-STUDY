#include <iostream>
#include <algorithm>
using namespace std;
 
struct info {
    long long num;
    int len;
};
 
int n;
int maxLen;
info arr[1000];
 
int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        maxLen = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr[i].num = tmp;
            arr[i].len = 1;
        }
 
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i].num <= arr[j].num) {
                    if (arr[i].len + 1 > arr[j].len) {
                        arr[j].len = arr[i].len + 1;
                    }
                }
            }
        }
 
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, arr[i].len);
        }
 
        cout << "#" << t << " " << maxLen << '\n';
    }
    return 0;
}