#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int arr[1001];
    int N,L;
    cin>>N>>L;
    for(int i = 0; i<N; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    
    int cnt;
    cnt = 1;
    
    int now = arr[0];
    
    for(int i = 1; i<N; i++)
    {
        if(arr[i] - now <L)continue;
        else
        {
            now = arr[i];
            cnt++;
        }
    }
    cout<<cnt;
    
    
}