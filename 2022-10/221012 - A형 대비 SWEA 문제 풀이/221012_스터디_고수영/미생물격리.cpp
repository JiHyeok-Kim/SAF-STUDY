#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int N,M,K;

struct Node{
    int x;
    int y;
    int val;
    int vect;
};

bool cmp (Node t, Node v){
    if (t.x>v.x) return 1;
    if(t.x<v.x) return 0;
    
    if(t.y>v.y) return 1;
    if(t.y<v.y )return 0;
    
    if(t.val>v.val) return 1;
    if(t.val<v.val) return 0;
    
    return t.x>v.x;
};

//0.X 1.상 2.하 3.좌 4.우
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

vector<Node>V;

int map[110][110] = {0,};

void input()
{
    cin>>N>>M>>K;
    
    for(int i = 0; i<K; i++)
    {
        int x,y,val,vect;
        cin>>x>>y>>val>>vect;
       
        V.push_back({x,y,val,vect});
        
    }
    
    
}

void move()
{
    for(int i = 0; i<V.size(); i++)
    {
        //if(V[i].val == 0)continue;
        
        int nx = V[i].x + dx[V[i].vect];
        int ny = V[i].y + dy[V[i].vect];
        
        //약품에 묻을 경우
        if(nx==0 || ny == 0 || nx==N-1 || ny==N-1)
        {
            //전체 개수 감소
            V[i].val = V[i].val/2;
            //방향 전환
            if(V[i].vect == 1) V[i].vect = 2;
            else if(V[i].vect == 2) V[i].vect = 1;
            else if(V[i].vect == 3) V[i].vect = 4;
            else if(V[i].vect == 4) V[i].vect = 3;
        }
        //이동
        V[i].x = nx;
        V[i].y = ny;
                    
    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        //입력
        input();
        
        //움직이기
        for(int i = 0; i<M;i++)
        {
            //이동
            move();
            
            //정렬
            sort(V.begin(), V.end(), cmp);
            
            //
            for(int j = 0; j<V.size(); j++)
            {
                for(int k = 1; k<4; k++)
                {
                    if(j+k>V.size()-1)continue;
                    if((V[j].x == V[j+k].x)&&(V[j].y == V[j+k].y))
                    {
                        V[j+k].vect = V[j].vect;
                        V[j].val+=V[j+k].val;
                        V[j+k].val = 0;
                    }
                    else break;
                }

            }
        }
        
        int result = 0;
        for(int i = 0; i<K; i++)
        {
            result+=V[i].val;
        }
        V.clear();
        cout<<"#"<<tc<<" "<<result<<"\n";
    }
    return 0;
}