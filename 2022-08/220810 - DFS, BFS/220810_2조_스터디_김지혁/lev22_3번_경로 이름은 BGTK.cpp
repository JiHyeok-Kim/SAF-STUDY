#include <iostream>
using namespace std;

char path[4];
char name[5] = "BGTK";
int n;

void run(int lev)
{
    if (lev == n)
    {
        cout << path << "\n";
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }

    return;
}

int main()
{
    cin >> n;
    run(0);

    return 0;
}