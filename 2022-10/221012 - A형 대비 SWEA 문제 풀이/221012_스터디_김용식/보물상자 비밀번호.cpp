#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
 
using namespace std;
 
vector<int> v;
vector<long long> con;
int tc;
int N;
int K;
string Password;
string change;
 
void input() {
    cin >> N >> K;
    cin >> Password;
    return;
}
 
void spin() {
    change = Password[Password.length() - 1];
    for (int i = 0; i < Password.length() - 1; i++) {
        change += Password[i];
    }
     
    Password = change;
 
    return;
}
 
int Find(string Num) {
     
    int hex = 16;
    int Sum = 0;
    int ch = 0;
    for (int i = Num.length()-1; i >=0; i--) {
        if ('0' <= Num[i] && Num[i] <= '9') Sum = Num[i] - '0';
        else if ('A' <= Num[i] && Num[i] <= 'Z') Sum = Num[i] - 'A' + 10;
         
        if (i == Num.length()-1) ch += Sum;
        if (i == Num.length()-2) ch += (16) * Sum;
        if (i < Num.length()-2)ch += (hex * 16) * Sum;
        if (i < Num.length()-2)hex = hex * 16;
    }
 
    return ch;
}
 
int COM(int num) {
    for (int i = 0; i <con.size(); i++) {
        if (v[i] == num) return 1;
    }
    return 0;
}
 
 
void confirm() {
    int consume = 0;
    int Pa = N/4;
 
    while (1) {
        string Num = "";
        if (consume == N)break;
 
 
        for (int i = consume; i < Pa+consume; i++) {
            Num += Password[i];
        }
         
        int Ret = Find(Num);
        int ans = COM(Ret);
        if (ans == 1) {
            consume += Pa;
            continue;
        }
        else {
            con.push_back(Ret);
            v.push_back(Ret);
        }
 
        consume += Pa;
    }
 
 
    return;
}
 
 
void solve() {
 
    int consume = 0;
    int Pa = N / 4;
 
    while (1) {
        if (consume == Pa)break;
         
        spin();
        confirm();
 
        consume++;
    }
 
}
 
void result() {
     
    sort(v.begin(), v.end(), greater<>());
 
    return;
}
 
void clear() {
    con.clear();
    v.clear();
     
    return;
}
int main() {
//  freopen_s(new FILE*, "input.txt", "r", stdin);
 
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        input();
        solve();
        result();
 
        cout << "#" << TC << " " << v[K-1] << '\n';
 
        clear();
    }
 
    return 0;
}