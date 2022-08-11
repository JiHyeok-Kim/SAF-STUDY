#include <iostream>
using namespace std;

char path[10];
int n;
int cnt;

int isPossible(int level)
{
    if (level < 3) return 1;
    if (path[level - 3] != path[level - 2]) return 1;
    if (path[level - 2] != path[level - 1]) return 1;

    return 0;
}

void run(int level)
{
    if (isPossible(level) == 0) return;

    if (level == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        path[level] = 'A' + i;
        run(level + 1);
        path[level] = 0;
    }
}

int main()
{
    cin >> n;
    run(0);
    cout << cnt;
    return 0;
}