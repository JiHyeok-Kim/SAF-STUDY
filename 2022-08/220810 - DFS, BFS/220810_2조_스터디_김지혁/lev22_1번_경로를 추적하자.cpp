#include <iostream>
using namespace std;

char path[3];
char name[3] = { 'A','B','C' };

void run(int lev)
{
    if (lev == 2)
    {
        cout << path << "\n";
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }

    return;
}

int main()
{
    run(0);

    return 0;
}