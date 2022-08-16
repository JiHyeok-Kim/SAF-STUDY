#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
string arr;
int sl;
int mid;

int bs(int s, int e)
{
    int marking = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == '#')
        {
            s = mid + 1;
            marking = mid;

        }
        else e = mid - 1;
    }
    if (marking != -1)return marking + 1;
    else return mid;

}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr;
        sl = arr.size();
        int ret = bs(0, sl - 1);
        int result = (ret * 100) / sl;
        cout << result << "%" << '\n';

    }

}