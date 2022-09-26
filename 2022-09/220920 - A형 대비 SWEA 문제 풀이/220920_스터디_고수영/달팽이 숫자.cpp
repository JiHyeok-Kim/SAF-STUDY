#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
};

int map[12][12] = {0,};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// 0: 오른쪽
// 1: 아래
// 2: 왼쪽
// 3: 위
int T;
int N;

int vect = 0;
Point start = {0,0};
queue<Point>q;

void output()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void clean()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            map[i][j] = 0;
        }
    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<=T; tc++)
    {
        cin>>N;
        q.push(start);
        int i = 1;
        vect = 0;
        
        map[start.x][start.y] = i;
    
        while(1)
        {
            Point now = q.front();
            q.pop();
            
            //map[now.x][now.y] = i;
            Point next;
            
            next.x = now.x + dx[vect];
            next.y = now.y + dy[vect];
            //조건사항
            if(next.x <0 ||next.y<0||next.x>=N||next.y>=N||map[next.x][next.y]!=0)
            {
                //오 -> 아래
                if(vect == 0)
                {
                    vect = 1;
                    
                    next.x = now.x + dx[vect];
                    next.y = now.y + dy[vect];
                    if(next.x <0 ||next.y<0||next.x>=N||next.y>=N||map[next.x][next.y]!=0)
                    {
                        cout<<"#"<<tc<<" "<<'\n';
                        output();
                        clean();
                        break;
                    }
                    i++;
                    map[next.x][next.y] = i;
                    
                    q.push({next.x,next.y});

                    
                }
                //아래 -> 왼
                else if(vect == 1)
                {
                    vect = 2;
                    
                    next.x = now.x + dx[vect];
                    next.y = now.y + dy[vect];
                    if(next.x <0 ||next.y<0||next.x>=N||next.y>=N||map[next.x][next.y]!=0)
                    {
                        cout<<"#"<<tc<<" "<<'\n';
                        output();
                        clean();
                        break;
                    }
                    i++;
                    map[next.x][next.y] = i;
                    
                    q.push({next.x,next.y});


                    
                }
                //왼 -> 위
                else if(vect == 2)
                {
                    vect = 3;
                    
                    next.x = now.x + dx[vect];
                    next.y = now.y + dy[vect];
                    if(next.x <0 ||next.y<0||next.x>=N||next.y>=N||map[next.x][next.y]!=0)
                    {
                        cout<<"#"<<tc<<" "<<'\n';
                        output();
                        clean();
                        break;
                    }
                    i++;
                    map[next.x][next.y] = i;
                    
                    q.push({next.x,next.y});


                }
                //위 -> 오
                else if(vect == 3)
                {
                    vect = 0;
                    
                    next.x = now.x + dx[vect];
                    next.y = now.y + dy[vect];
                    if(next.x <0 ||next.y<0||next.x>=N||next.y>=N||map[next.x][next.y]!=0)
                    {
                        cout<<"#"<<tc<<" "<<'\n';
                        output();
                        clean();
                        break;
                    }
                    i++;
                    map[next.x][next.y] = i;
                    
                    q.push({next.x,next.y});

                }
            }
            else
            {
                i++;
                map[next.x][next.y] = i;
                
                q.push({next.x,next.y});
            }
            
        }
    }
    
    
}
