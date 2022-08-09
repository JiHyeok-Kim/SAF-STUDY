#include <iostream>
using namespace std;

int main()
{
    char arr[3][5] = { {'F','R','Q','W','T'},{'G','A','S','Y','Q'},{'A','S','A','D','B'} };
    int n;
    cin >> n;

    for (int y = 0; y < 3; y++) {
        cout << arr[y][n];
    }

    return 0;
}