#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
};

int T;
int N,K;
int map[10][10] = {0,};
int used[10][10] = {0,};
int maxi = -21e6;
int result = -21e7;
int Kflag = 0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<point>maxNum;

void input()
{
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            
            cin>>map[i][j];
            
            //최대높이 저장
            if(map[i][j]>maxi)
            {
                maxNum.clear();
                maxNum.push_back({i,j});
                maxi = map[i][j];
            }
            else if(map[i][j] == maxi)
            {
                maxNum.push_back({i,j});
            }
        }
    }
}

void dfs(point now,int cnt)
{
    //높은거 비교
    result = max(cnt,result);
    
    for(int i = 0; i<4; i++)
    {
        int nx = now.x + dx[i];
        int ny = now.y + dy[i];
        
        if(nx<0||ny<0||nx>=N||ny>=N)continue;
        if(used[nx][ny] == 1)continue;
        
        //다음 갈곳이 현재보다 높거나 같을때
        if(map[nx][ny]>=map[now.x][now.y])
        {
            //K로 갈 수 있을때
            if(map[nx][ny]-K<map[now.x][now.y])
            {
                //한번도 안갔을때
                if(Kflag == 0)
                {
                    for(int k = 1; k<=K; k++)
                    {
                        Kflag = 1;
                        int tmp = map[nx][ny];
                        map[nx][ny] = map[now.x][now.y]-k;
                        used[nx][ny] = 1;
                        dfs({nx,ny},cnt+1);
                        used[nx][ny] = 0;
                        map[nx][ny] = tmp;
                        Kflag = 0;
                    }
                }
                //이미 갔을때
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
        //다음 갈곳이 낮을 경우
        else
        {
            used[nx][ny] = 1;
            dfs({nx,ny},cnt+1);
            used[nx][ny] = 0;
        }
    }
    
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        //입력
        maxi = -21e6;
        result = -21e7;
        input();
        //모든 정상 탐색
        for(int i = 0; i<maxNum.size(); i++)
        {
            used[maxNum[i].x][maxNum[i].y] = 1;
            dfs(maxNum[i],1);
            used[maxNum[i].x][maxNum[i].y] = 0;
        }
        cout<<"#"<<tc<<" "<<result<<"\n";
    }
    return 0;
}