#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int T;
char D;
int A,B;
int INF = 1000001;
int num[1000001]= {0,};
int used[1000001][10] = {0,};

int cnt = 0;

//소수 지정
void sosu()
{
    for(int i = 2; i<sqrt(INF)+1; i++)
    {
        if(num[i] == 1) continue;
        int j = 2;
        while(i*j<=INF)
        {
            num[i*j] = 1;
            j++;
        }
    }
}
void find(int start,int end,char C)
{
    for(int i = start; i<=end; i++)
    {
        if(num[i] == 0)
        {
            string tmp;
            tmp = to_string(i);
            int x = tmp.find(C);
            if(x== -1) continue;
            cnt++;
        }
    }
}


int main()
{
    num[0] = 1;
    num[1] = 1;
    sosu();
    cin>>T;
    for(int tc = 1; tc<=T; tc++)
    {
        cnt = 0;
        cin>>D>>A>>B;
        find(A,B,D);
        cout<<"#"<<tc<<" "<<cnt<<"\n";
        
        
        
    }
    
    
}
