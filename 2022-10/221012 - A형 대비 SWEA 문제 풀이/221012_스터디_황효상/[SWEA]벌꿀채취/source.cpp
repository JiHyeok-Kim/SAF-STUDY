#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int T, N, M, C;
int map[11][11];
int start_x, start_y;
bool check[10];
int maxi;
int ans = 0;
void dfs(int sum,int amount,int idx) {
    bool checker = 0;
    for (int a = idx; a < start_y+M; ++a) {
        int gop = map[start_x][a] * map[start_x][a];
        if (!check[a] && amount+map[start_x][a] <= C) {
            if (checker == 0)
                checker = 1;
            check[a] = 1;
            dfs(sum + gop,amount+map[start_x][a],a+1);
            check[a] = 0;
        }
    }

    if(checker==0)
        if (sum > maxi)
            maxi = sum;
}
int getMaxi(int x,int y) {
    start_x = x;
    start_y = y;
    maxi = 0;
    dfs(0,0,start_y);
    return maxi;
}
int solve() {


    for (int a = 0; a < N; ++a) {
        for (int b = 0; b <= N - M; ++b) {
            int honey = getMaxi(a,b);

            for (int c = a ; c < N; ++c) {
                for (int d = 0; d <= N-M; ++d) {
                    if (c == a && d < b + M) continue;
                    int temp_honey = getMaxi(c, d);
                    if (ans < honey + temp_honey)
                        ans = honey + temp_honey;
                }
            }
        }
    }

    return ans;
}
void input() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M >> C;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
                cin >> map[a][b];
            }
        }
        cout << "#"<<t<< " " << solve() << "\n";
        ans = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen_s(new FILE*, "input.txt", "r", stdin); //리소스파일에 넣기
    input();
    return 0;
} 
