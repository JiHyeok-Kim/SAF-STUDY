#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
string str;
 
int ret;
 
void getPair(char ch, int idx) {
    for (int i = idx + 1; i < str.size(); i++) {
        if (str[i] == ch) {
            string left, mid, right;
            string newStr;
            left = str.substr(0, idx);
            mid = str.substr(idx + 1, i - idx - 1);
            right = str.substr(i + 1, str.size() - i);
            newStr = left + mid + right;
            str = newStr;
            ret = 1;
            return;
        }
    }
}
 
int main() {
    int tc;
    cin >> tc;
     
    for (int t = 1; t <= tc; t++) {
        cin >> str;
 
        for (int i = 0; i < str.size() - 1; i++) {
            if (str.size() == 0) break;
            getPair(str[i], i);
            if (ret) {
                i--;
                ret = 0;
            }
        }
 
        sort(str.begin(), str.end());
 
        if (str.size() == 0) cout << "#" << t << " " << "Good" << '\n';
        else cout << "#" << t << " " << str << '\n';
    }
    return 0;
}