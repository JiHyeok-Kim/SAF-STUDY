#include <iostream>

#include <string>
using namespace std;

int n;
string name = "BTSKR";
int via[10];
int cnt;

void run(int level)
{
    if (level == n)
    {
        if (via[2] == 1) //S�� ���ԵǾ��������� (S�� 2��index)
        {
            cnt++;
        }
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (via[i] == 0)
        {
            via[i] = 1;
            run(level + 1);
            via[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    run(0);
    cout << cnt;

    return 0;
}
