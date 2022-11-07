#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<vector<int>> v;
bool check[101];
int N,M;

void dfs(int idx){
    check[idx] = false;
    for(int a=0; a<v[idx].size(); ++a){
        int next = v[idx][a];
        if(check[next]){
            dfs(next);
        }
    }
}

int main(){
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int t= 1;t <= T; ++t){
        cin >> N >> M;
        v = vector<vector<int>>(N+1, vector<int>());
        memset(check, true, sizeof(check));

        int x, y;
        for(int a=0; a< M; ++a){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(check[i]){
                cnt++;
                dfs(i);
            }
        }
        
        cout << "#" << t << " " << cnt << "\n";
    }
}
