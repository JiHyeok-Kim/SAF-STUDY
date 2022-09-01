#include <vector>

#include <queue>

#include <string>

#include <cstring>

#include <math.h>

#include <algorithm>

#include <iostream>

using namespace std;

int map[10][10] = {0};

//x,y,범위,충전량
struct Node{
    int x;
    int y;
    int range;
    int val;
};
struct Point{
    int x;
    int y;
};

int T,M,A;

Node pA,pB;
Node nA,nB;

int retA = 0,retB = 0;

int cntA = 0,cntB = 0;

int dx[] = {0,-1,0,1,0};//정지 상 우 하 좌
int dy[] = {0,0,1,0,-1};

int maxA,maxB,secA,secB;

vector<int>vA;
vector<int>vB;
vector<Node>BC;

vector<int>usedA;
vector<int>usedB;

bool cmp(int t, int v)
{
    return t>v;
}

void input()
{
    cin>>M>>A;
    //M
    //이동 A입력
    for(int i = 0; i<M; i++)
    {
        int x;
        cin>>x;
        vA.push_back(x);
    }
    //이동 B입력
    for(int i = 0; i<M; i++)
    {
        int x;
        cin>>x;
        vB.push_back(x);
    }
    //A
    for(int i = 0; i<A; i++)
    {
        int y,x,range,val;
        cin>>y>>x>>range>>val;

        map[x-1][y-1] = i+1;
        BC.push_back({y-1,x-1,range,val});
    }
}

void check()
{
    for(int i = 0; i<usedA.size(); i++)
    {
        if(usedA[i]!=0 && usedA[i]==usedB[i])
        {
            if(cntA>1)
            {
                maxA = usedA[0];
                secA = usedA[1];
                if(cntB>1)
                {
                    maxB = usedB[0];
                    secB = usedB[1];
                }
                if(secA>=secB)
                {
                    retA+=maxA;
                    retB+=secB;
                    return;
                }
                else
                {
                    retA+=secA;
                    retB+=maxB;
                    return;
                }
            }


        }
    }
}

void run()
{
    for(int i = 0; i<M; i++)
    {
        cntA = 0;
        cntB = 0;
        maxA = 0,maxB = 0,secA = 0,secB = 0;
        //이동 좌표
        nA = {nA.x + dx[vA[i]], nA.y + dy[vA[i]]};
        nB = {nB.x + dx[vB[i]], nB.y + dy[vB[i]]};

        //매좌표값마다
        //거리 계산 및 비교
        for(int j = 0; j<BC.size(); j++)
        {
            //거리
            int aD = abs(nA.x-BC[j].x) + abs(nA.y - BC[j].y);
            int bD = abs(nB.x-BC[j].x) + abs(nB.y - BC[j].y);

            // A가 j번째 충전소 범위내에 있을경우
            if(aD<=BC[i].range)
            {
                usedA.push_back(BC[i].val);
                cntA++;
            }
            else usedA.push_back(0);

            // B가 j번째 충전소 범위내에 있을경우
            if(bD <= BC[i].range)
            {
                usedB.push_back(BC[i].val);
                cntB++;
            }
            else usedB.push_back(0);
        }

        //내림차순 정렬
        sort(usedA.begin(),usedA.end(),cmp);
        sort(usedB.begin(),usedB.end(),cmp);

        //비교
        check();


    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        //충전범위 입력

        //사용자
        pA = {0,0};
        pB = {9,9};
        nA = pA;
        nB = pB;

        retA = 0;
        retB = 0;

        run();

        int debug = 1;





    }
}