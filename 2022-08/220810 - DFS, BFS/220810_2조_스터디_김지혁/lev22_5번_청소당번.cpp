#include <iostream>
using namespace std;

char path[10];
int n;

void run(int lev)
{
    if (lev == 4)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        path[lev] = '1' + i;
        run(lev + 1);
    }

    return;
}

int main()
{
    cin >> n;
    run(0);

    return 0;
}