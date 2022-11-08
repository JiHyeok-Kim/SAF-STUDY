#include <iostream>
using namespace std;

int main()
{
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        long long k, temp;
        cin >> k;
        long long a = 2, b = 1;
        for (int i = 0; i < k - 1; i++) {
            temp = a + b;
            b = a;
            a = temp;
        }
        cout << "#" << tc << " " << a << " " << b << "\n";
    }

    return 0;
}