#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string st = "ABCD";
string ist;
int cnt;

void run(int lev, string path) {
    if (lev == 3) {
        cnt++;
        if (path == ist) {
            cout << cnt << "¹øÂ°" << endl;
            return;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        run(lev+1, path+st[i]);
    }
}


int main() {
    cin >> ist;
    run(0, "");
    
    return 0;
}
