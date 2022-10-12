#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int T;
int N;

int maxi = -21e7;
int mini = 21e7;
//연산자 개수
int pmgn[4] = {0,};
vector<int>num;
vector<char>PMGN;
int used[15] = {0,};

int result;

void input()
{
    cin>>N;
    
    //연산자 입력
    for(int i = 0; i< 4; i++)
    {
        cin>>pmgn[i];
    }
    //숫자 입력
    for(int i = 0; i<N; i++)
    {
        int x;
        cin>>x;
        num.push_back(x);
    }
}


void dfs(int result, int cnt)
{
    if(cnt == N-1)
    {
        maxi = max(maxi,result);
        mini = min(mini,result);
        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        //dfs 연산자
        if(pmgn[i] != 0)
        {
            pmgn[i]-=1;
            if( i == 0)dfs(result+num[cnt+1],cnt+1);
            else if(i == 1)dfs(result-num[cnt+1],cnt+1);
            else if(i == 2)dfs(result*num[cnt+1],cnt+1);
            else if(i == 3)dfs(result/num[cnt+1],cnt+1);
            pmgn[i]+=1;
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
        maxi = -21e7;
        mini = 21e7;
        //연산자 벡터 생성
        result = num[0];
        
        dfs(result,0);
        
        result = maxi - mini;
        cout<<"#"<<tc<<" "<<result<<"\n";
        num.clear();
        PMGN.clear();
    }
    return 0;
}