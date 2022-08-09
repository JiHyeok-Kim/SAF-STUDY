#include <iostream>
#include <string>
using namespace std;

char alphabet[5][3] = {
    {'A', 'B', 'C'},
    {'A', 'G', 'H'},
    {'H', 'I', 'J'},
    {'K', 'A', 'B'},
    {'A', 'B', 'C'}
};
int dat[130];

int main() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 3; x++) {
            dat[alphabet[y][x]]++;
        }
    }
    for (int x = 'A'; x <= 'Z'; x++) {
        for (int i = 0; i < dat[x]; i++) {
            cout << (char)x;
        }
    }


    return 0;
}