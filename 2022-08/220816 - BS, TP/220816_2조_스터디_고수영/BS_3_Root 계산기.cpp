#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

long long INF = 10000001;
long long arr[10000001] = { 0 };
int target;
long long mid;
int max_num;


int bs(long long s, long long e)
{
    while (s <= e)
    {
        mid = (s + e) / 2;

        if (arr[mid] * arr[mid] == target) return arr[mid];
        else
        {
            if (arr[mid] * arr[mid] > target) e = mid - 1;
            else
            {
                max_num = arr[mid];
                s = mid + 1;
            }

        }
        
    }
    return max_num;
}


int main()
{
    for (long long i = 0; i < INF; i++)
        arr[i] = i + 1;
    cin >> target;
    int ret =  bs(0,INF-1);
    cout << ret;
}