#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;
int arr[100001] = {0};
int n,k;
int target;

int bs(int s, int e)
{
    while(s<=e)
    {
        int mid = (s+e)/2;
        if (arr[mid] == target)return 1;
        if (arr[mid]>target) e = mid -1;
        else s = mid+1;
    }
    return 0;
}

int flag = 0;
int main()
{
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    sort(arr,arr+n);
                
    for(int i = 0; i<k; i++)
    {
        cin>>target;
        int ret = bs(0,n-1);
        if (ret == 1)cout<<"O";
        else cout<<"X";
        
    }
}