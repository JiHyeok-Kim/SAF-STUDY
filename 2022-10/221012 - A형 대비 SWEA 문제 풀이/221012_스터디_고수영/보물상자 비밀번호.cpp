#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int N,K;
int cnt = 0;
int result = 0;
string str;
string now;
vector<string>v;

bool cmp(string t, string v)
{
    return t>v;
}

void input()
{
    cin>>N>>K;
    cin>>str;
}
void split()
{
    int start = 0;
    for(int i = 0; i<4; i++)
    {
        int flag = 0;
        string tmp = str.substr(start,N/4);
        for(int j = 0; j<v.size();j++)
        {
            if(v[i]==tmp)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0) v.push_back(tmp);
        start = start + N/4;
    }
}
void turn()
{
    for(int i = 0; i<(N/4);i++)
    {
        split();
        string tmp = str.substr(0,str.length()-1);
        string tmp1 = str.substr(str.length()-1,1);
        str = tmp1+tmp;
    }
}
void change10(string now)
{
    int d = now.size();
    int arr[30] = {0,};
    
    //10진수로 변경
    for(int i = 0; i<d; i++)
    {
        if(now[i]>='A'&&now[i]<='F')
        {
            arr[i] = int(now[i])-55;
        }
        else
        {
            arr[i] = int(now[i]-'0');
        }
    }
    //16지수 곱
    int H = d-1;
    for(int i = 0; i<d; i++)
    {
        result += arr[i] * pow(16,H);
        H--;
    }
    
    for(int i = 0; i<30; i++) arr[i] = 0;
}
int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        result = 0;
        cnt = (N/4)-1;
        
        turn();
        sort(v.begin(), v.end(), cmp);
        
        now = v[K-1];
        
        //10진수로 변환
        change10(now);
        v.clear();
        
        
        cout<<"#"<<tc<<" "<<result<<"\n";
    }
    return 0;
}