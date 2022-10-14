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
    int len;
};

int T,N,M;
int map[25][25] = {0,};
int used[25][25] = {0,};

int map_cnt = 0;
int home_cnt = 0;
int maxi = -21e6;
int maxi_i = 0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<point>q;
vector<point>v;

void input()
{
    cin>>N>>M;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 1)
            {
                //집 위치 벡터에 입력
                v.push_back({i,j,1});
            }
        }
    }
}

void clear()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            used[i][j] = 0;
        }
    }
}


void run(point tmp,int i)
{
    //맵 크기만큼 반지름을 점점 키움
    //집을 담은 v에서 탐색 하기때문에 기본 1
    //for(int i = 1; i<=N+1; i++)
    //{
        //처음 시작 지점
        q.push(tmp);
        used[tmp.x][tmp.y] = 1;
        
        home_cnt = 0;
        map_cnt = 1;
        
        if(map[tmp.x][tmp.y]==1)home_cnt++;
        //해당 i에서 원래 총 범위
        int area = pow(i, 2) + pow(i-1, 2);
        
        //flood fill
        while(!q.empty())
        {
            point now = q.front();
            q.pop();
            
            for(int j = 0; j<4; j++)
            {
                int nx = now.x + dx[j];
                int ny = now.y + dy[j];
                int nlen = now.len + 1;
                
                if(nx<0||ny<0||nx>=N||ny>=N)continue;
                if(nlen>i)continue;
                if(used[nx][ny]!=0)continue;
                if(map[nx][ny] == 1) home_cnt++;
                
                used[nx][ny] = nlen;
                map_cnt++;
                
                q.push({nx,ny,nlen});
                
            }
        }
        //비용 구하기
        clear();
        int pay = (home_cnt*M) - area;
        //int ppp = (v.size()*M);
        
        
        
        if(pay>=0)
        {
            if(home_cnt>maxi)
            {
                maxi = home_cnt;
                maxi_i = i;
            }
        }
        
        
        
    //}
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        //입력
        input();
        maxi = -21e6;
        int H = 0;
        for(int K = 1; K<=N+1;K++)
        {
            if(K%2==1)
            {
                H = K/2;
            }
            for(int i = H; i<N; i++)
            {
                for(int j=H;j<N; j++)
                {
                    run({i,j,1},K);
                }
            }
        }
        
        cout<<"#"<<tc<<" "<<maxi<<"\n";
        
    }
    return 0;
}