#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int used[1001] = { 0 };
int N;
int cnt;
int num;
int path[3];


vector<int> v1;

void prime()
{
    used[0] = 1;
    used[1] = 1;


    for (int i = 2; i < 1000; i++)
    {
        if (used[i] == 0)
        {
            for (int j = i * 2; j < 1000; j += i)
            {
                used[j] = 1;
            }
        }
    }
    
}

void run(int lev,int n,int sn)
{
    if (lev == 3)
    {
        if (sn == N) cnt++;
        return;
    }
    for (int i = n; i < v1.size(); i++)
    {
        if ((sn + v1[i]) > N) return;
        path[lev] = v1[i];
        run(lev + 1,i,sn+v1[i]);
    }
    return;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prime();
    int de = 0;
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        for (int i =2; i < N; i++)
        {
            if (used[i] == 0)
            {
                v1.push_back(i);
            }
        }
        cnt = 0;
        
        run(0,0,0);
        cout << '#' << tc + 1 << ' ' << cnt << '\n';
        cnt = 0;
        v1.clear();

    }



    return 0;
}