#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n;
vector<int> v;
int path[8] = { 0 };
int path2[2] = { 0, };
int Maop[16][16] = { 0 };
int sum = 0;
void dfs2(int lev) {
    if (lev == 2) {
        sum += Maop[path2[0]][path2[1]];
        return;
    }
     
    for (int i = 0; i < n / 2; i++) {
        path2[lev] = path[i];
        dfs2(lev+1);
         
    }
 
}
 
void dfs(int now, int lev) {
    if (lev == n / 2) {
        dfs2(0);
        v.push_back(sum);
        sum = 0;
        return;
    }
    for (int i = now; i < n; i++) {
        path[lev] = i;
        dfs(i+1, lev + 1);
         
    }
     
}
void init() {
    v.clear();
    memset(Maop, 0, sizeof(Maop));
    memset(path, 0, sizeof(path));
    memset(path2, 0, sizeof(path2));
     
    return; 
}
 
 
int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> Maop[i][j];
            }
        }
 
        dfs(0, 0);
        int mini = 21e8;
        for (int i = 0; i < v.size() / 2; i++) {
            mini = min(abs(v[i] - v[v.size()-1 - i]),mini);     
        }
        cout <<"#" <<TC<<" " << mini << '\n';
        init();
    }
     
     
 
    return 0;
}