#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int T,N,K;
int cnt = 0;

int map[20][20] = {0,};
int used[20][20] = {0,};

void input()
{
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }
}

void clean()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            used[i][j] = 0;
        }
    }
}

void dfs_D(int lev,Point now)
{
    if(lev == K-1)
    {
        //벽일때
        if(now.x+1 == N)
        {
            cnt++;
            return;
        }
        //다음칸도 빈칸일때
        if(map[(now.x)+1][now.y]!=0)
            return;
       
        cnt++;
        return;
    }
    
    for(int i = 0; i<1; i++)
    {
        int nx = now.x + 1;
        int ny = now.y;
        if(nx<0||ny<0||nx>=N||ny>=N) continue;
        if(map[nx][ny] == 0)continue;
        dfs_D(lev + 1, {nx,ny});
    }
}

void dfs_R(int lev,Point now)
{
    if(lev == K-1)
    {
        //벽일때
        if(now.y+1 == N)
        {
            cnt++;
            return;
        }
        //다음칸도 빈칸일때
        else if(map[now.x][(now.y)+1]==0)
            cnt++;
            return;
       
        return;
    }
    
    for(int i = 0; i<1; i++)
    {
        int nx = now.x;
        int ny = now.y + 1;
        if(nx<0||ny<0||nx>=N||ny>=N) continue;
        if(map[nx][ny] == 0)continue;
        dfs_R(lev + 1, {nx,ny});
    }
}




int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        cnt = 0;
        
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                //빈칸일때
                if(map[i][j] == 1)
                {
                    //위
                    if(i-1<0)
                    {
                        dfs_D(0,{i,j});
                    }
                    else if(i-1>=0)
                    {
                        if(map[i-1][j]==0)dfs_D(0,{i,j});
                    }
                    //왼쪽
                    if(j-1<0)
                    {
                        dfs_R(0,{i,j});
                    }
                    else if(j-1>=0)
                    {
                        if(map[i][j-1]==0)dfs_R(0,{i,j});
                    }

                }
            }
        }
        
        cout<<"#"<<tc<<" "<<cnt<<'\n';
    }
    
    
    return 0;
}