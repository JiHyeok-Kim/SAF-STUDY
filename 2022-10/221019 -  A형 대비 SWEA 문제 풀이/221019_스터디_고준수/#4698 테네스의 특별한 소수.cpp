#include <iostream>
#include <string>
using namespace std;

int used[1000001] = {0};

int main(void)
{

    int t;
    cin >> t;
    used[0] = 1;
    used[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        if (used[i]==0)
        {
            for (int j = i + i; j <= 1000000; j += i)
                used[j] = 1;
        }
    }

    for (int tc = 1; tc <= t; tc++)
    {
        int D;
        int A;
        int B;
        int cnt = 0;
        string str_num;
        cin >> D >> A >> B;

        str_num = to_string(D);
        for (int i = A; i <= B; i++)
        {
            if (used[i]==0)
            {
                string str_allnum;
                str_allnum = to_string(i);

                if (str_allnum.find(str_num) != -1)
                    cnt++;
               
            }
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}