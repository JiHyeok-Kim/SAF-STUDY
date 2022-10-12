#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int T;
int M,A;

struct BC{
    int y;
    int x;
    int range;
    int val;
};

struct point{
    int x;
    int y;
};

struct used{
    int name;
    int val;
};

//0: 정지 1: 상 2: 우 3: 하 4: 좌
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};

vector<int>moveA;
vector<int>moveB;
vector<BC>bc;

point VA;
point VB;

vector<used>BC_A;
vector<used>BC_B;

int result;

bool cmp (used t, used v)
{
    return t.val>v.val;
}

void input()
{
    cin>>M>>A;
    //A 이동경로
    for(int i = 0; i<M; i++)
    {
        int mA;
        cin>>mA;
        moveA.push_back(mA);
    }
    //B 이동경로
    for(int i = 0; i<M; i++)
    {
        int mB;
        cin>>mB;
        moveB.push_back(mB);
    }
    
    //BC 정보 입력
    for(int i = 0; i<A; i++)
    {
        int y,x,range,val;
        cin>>y>>x>>range>>val;
        
        bc.push_back({y-1,x-1,range,val});
    }
    
}

void Find()
{
    //BC범위 안에 있는지
    for(int i = 0; i<bc.size(); i++)
    {
        int dA = abs(VA.x - bc[i].x) + abs(VA.y - bc[i].y);
        int dB = abs(VB.x - bc[i].x) + abs(VB.y - bc[i].y);
        
        //A
        if(dA<=bc[i].range)
        {
            BC_A.push_back({i+1,bc[i].val});
        }
        //B
        if(dB<=bc[i].range)
        {
            BC_B.push_back({i+1,bc[i].val});
        }
    }
    
    //정렬
    sort(BC_A.begin(),BC_A.end(),cmp);
    sort(BC_B.begin(),BC_B.end(),cmp);
    
    //둘다 0일때 return
    if(BC_A[0].val == 0 && BC_B[0].val == 0) return;
    
    
    //비교
    //둘이 개수가 같을때
    if(BC_A.size() == BC_B.size())
    {
        //최대 BC값이 다를때
        if(BC_A[0].name != BC_B[0].name)
        {
            result += BC_A[0].val;
            result += BC_B[0].val;
            //continue;
        }
        //같을때
        else
        {
            //1개일때
            if(BC_A.size() == 1)
            {
                result +=BC_A[0].val;
                //continue;
            }
            //아닐때
            else
            {
                //다음값 비교
                if(BC_A[1].val<=BC_B[1].val)
                {
                    result += BC_A[0].val;
                    result += BC_B[1].val;
                    //continue;
                }
                else
                {
                    result += BC_A[1].val;
                    result += BC_B[0].val;
                }
            }
        }

    }
    
    //둘이 개수가 다를때
    else
    {
        //최대 BC값이 다를때
        if(BC_A[0].name != BC_B[0].name)
        {
            result += BC_A[0].val;
            result += BC_B[0].val;
            //continue;
        }
        //같을때
        else
        {
//                            //다음값 비교
                if(BC_A[1].val<=BC_B[1].val)
                {
                    result += BC_A[0].val;
                    result += BC_B[1].val;
                    //continue;
                }
                else
                {
                    result += BC_A[1].val;
                    result += BC_B[0].val;
                }
//            }
        }
        
    }
    
    //초기화
    BC_A.clear();
    BC_B.clear();
    BC_A.push_back({0,0});
    BC_B.push_back({0,0});
}

void move(int now)
{
    int nx_a = VA.x + dx[moveA[now]];
    int ny_a = VA.y + dy[moveA[now]];
    
    int nx_b = VB.x + dx[moveB[now]];
    int ny_b = VB.y + dy[moveB[now]];
    
    VA ={nx_a,ny_a};
    VB ={nx_b,ny_b};
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        //입력
        input();
        VA = {0,0};
        VB = {9,9};
        BC_A.push_back({0,0});
        BC_B.push_back({0,0});
        result = 0;
        //계산
        for(int i = 0; i<M; i++)
        {
            Find();
            move(i);
        }
        Find();
        
        int p = result;
    
        cout<<"#"<<tc<<" "<<result<<"\n";
        moveA.clear();
        moveB.clear();
        BC_A.clear();
        BC_B.clear();
        bc.clear();
    }
    return 0;
}