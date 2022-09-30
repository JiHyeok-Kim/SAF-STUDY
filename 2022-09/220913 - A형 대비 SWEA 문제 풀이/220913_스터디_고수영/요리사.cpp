#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int N;
int map[20][20] = {0,};
int used[20] = {0,};

vector<int>v1;
vector<int>v2;
int sumA = 0;
int sumB = 0;
int result = 0;
int mini = 21e7;

void input()
{
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }
    
    
}

void CHECK()
{
    sumA = 0;
    sumB = 0;
    result = 0;
    
    //sumA
    for(int i = 0; i<v1.size(); i++)
    {
        for(int j = 0; j<v1.size(); j++)
        {
            if (v1[i]>=v1[j])continue;
            sumA += (map[v1[i]][v1[j]] + map[v1[j]][v1[i]]);
        }
    }
    
    //sumB
    for(int i = 0; i<v2.size(); i++)
    {
        for(int j = 0; j<v2.size(); j++)
        {
            if (v2[i]>=v2[j])continue;
            sumB += (map[v2[i]][v2[j]] + map[v2[j]][v2[i]]);
        }
    }
    
    //mini 체크
    result = abs(sumA-sumB);
    if(result<mini) mini = result;
}

void v2clear()
{
    while(v2.size()!=0)
    {
        v2.pop_back();
    }
}

void dfs(int lev,int now)
{
    if(lev == N/2)
    {
        for(int a = 0; a< N; a++)
        {
            if (used[a] == 0)
            {
                v2.push_back(a);
            }
        }
        CHECK();
        v2clear();
        return;
    }
    
    for(int i = now; i<N; i++)
    {
        if(used[i] == 1)continue;
        used[i] = 1;
        v1.push_back(i);
        dfs(lev+1,i);
        v1.pop_back();
        used[i] = 0;
    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        mini = 21e9;
        dfs(0,0);
        
        cout<<"#"<<tc<<" "<<mini<<"\n";
    }
    return 0;
}