#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;

int pay[4] = {0,};
int timeTable[12] = {0,};

int mini = 21e8;

void input()
{
    //비용 입력
    for(int i = 0; i<4; i++)
    {
        cin>>pay[i];
    }
    //이용 일수 입력
    for(int i = 0; i<12; i++)
    {
        cin>>timeTable[i];
    }
}

void dfs(int lev,int sum_val)
{
    if(lev >=12)
    {
        if(sum_val<mini)mini = sum_val;
        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        if(i == 0)
        {
            dfs(lev+1,sum_val + timeTable[lev]*pay[i]);
        }
        if(i == 1)
        {
            dfs(lev+1,sum_val + pay[i]);
        }
        if(i == 2)
        {
            dfs(lev+3,sum_val + pay[i]);
        }
        if(i == 3)
        {
            dfs(lev+12,sum_val + pay[i]);
        }
    }
    
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        //입력
        input();
        mini = 21e7;
        
        dfs(0,0);
        
        cout<<"#"<<tc<<" "<<mini<<"\n";
        
    }
    return 0;
}