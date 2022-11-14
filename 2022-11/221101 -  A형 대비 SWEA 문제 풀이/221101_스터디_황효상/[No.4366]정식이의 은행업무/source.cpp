#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
 
int T;
 
string two;
string three;
 
long long twoGop[40];
long long threeGop[40];
 
long long twoNum;
long long threeNum;
 
 
int bs(long long target) {
    int s = 0;
    int e = three.length() - 1;
    int ans = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
 
        if (threeGop[mid] > target) {
            e = mid - 1;
        }
        else if(threeGop[mid] == target){
            return mid;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
void getGop() {
    twoGop[0] = 1;
    threeGop[0] = 1;
 
    for (int a = 1; a < 40; ++a) {
        twoGop[a] = twoGop[a - 1] << 1;
        threeGop[a] = threeGop[a - 1] * 3;
    }
}
 
void getNum() {
    reverse(two.begin(), two.end());
    reverse(three.begin(), three.end());
    twoNum = 0;
    threeNum = 0;
    for (int a = 0; a < two.length(); ++a) {
        if (two[a] == '1') {
            twoNum += twoGop[a];
        }
    }
    for (int a = 0; a < three.length(); ++a) {
        int num = three[a] - '0';
        threeNum = threeNum + num * threeGop[a];
    }
}
 
int getAnswer(long long newTwo) {
    long long ans = 0;
 
    long long getChai = newTwo - threeNum;
 
    int flag = 1;
    if (getChai == 0) {
        return 0;
    }
    if (getChai < 0) {
        getChai = -getChai;
        flag = 0;
    }
     
    int idx;
    if (getChai < 3) {
        idx = 0;
    }
    else {
        if (getChai % 3 == 0)
            idx = bs(getChai);
        else
            return 0;
    }
    if (getChai%threeGop[idx] == 0) {
        int cnt = getChai / threeGop[idx];
        int tmp = three[idx] - '0';
        string ttmp = three;
        int ans = 0;
        if (flag) {
            ans = tmp + cnt;
        }
        else {
            ans = tmp - cnt;
            ttmp[idx] = char(ans);
        }
 
        if (ans >= 3 || ans < 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else
        return 0;
 
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("input.txt", "r", stdin);
 
    cin >> T;
 
    getGop();
 
    for(int t = 1; t<= T; ++t){
        cin >> two >> three;
 
        getNum();
        long long answer = 0;
        for (int a = 0; a < two.length(); ++a) {
            long long tmp = 0;
            if (two[a] == '0') {
                tmp = twoNum + twoGop[a];
            }
            else {
                tmp = twoNum - twoGop[a];
            }
            if (getAnswer(tmp)){
                answer = tmp;
                break;
            }
        }
        cout << "#" << t << " " << answer << "\n";
    }
 
}
