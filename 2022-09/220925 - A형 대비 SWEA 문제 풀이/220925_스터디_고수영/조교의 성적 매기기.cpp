#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
struct NAME{
    int index;
    int score;
};
vector<NAME>stu;
int T,N,K;

string point[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
bool cmp(NAME t,NAME v)
{
    return t.score>v.score;
}

void input()
{
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        float a, b, c;
        cin>>a>>b>>c;
        int tmp = ((a*35)+(b*45)+(c*20));
        stu.push_back({i+1,tmp});
    }
}


int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        sort(stu.begin(), stu.end(), cmp);
        
        int A = 0;
        int C = 0;
        
        for(int i = 0; i<stu.size(); i++)
        {
            if(stu[i].index == K)
            {
                A = i;
                break;
            }
        }
        int start = 0;
        string result = "";
        
        
        C = N/10;
        int D = A/C;
        result = point[D];
        
        
        cout<<"#"<<tc<<" "<<result<<'\n';
        stu.clear();
        
    }
    return 0;
}