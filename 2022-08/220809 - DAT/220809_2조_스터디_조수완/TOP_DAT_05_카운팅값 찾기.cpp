#include <iostream>
#include <string>
using namespace std;

int arr[3][5] = {
    {1, 3, 3, 5, 1},
    {3, 6, 2, 4, 2},
    {1, 9, 2, 6, 5}
};
int dat[10], target;

int main() {
    cin >> target;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 5; x++) {
            dat[arr[y][x]]++;
        }
    }
    for (int x = 1; x <= 9; x++) {
        if (dat[x] == target) {
            cout << x << " ";
        }
    }

    return 0;
}