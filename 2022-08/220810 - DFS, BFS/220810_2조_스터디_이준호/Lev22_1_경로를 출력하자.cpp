#include <iostream>
#include <string>
using namespace std;

char path[10];

void run(int lev) {
    if (lev == 2) {
        cout << path << "\n";
        return;
    }
    for (int i = 0; i < 3; i++) {
        path[lev] = 'A' + i;
        run(lev + 1);
    }
}


int main() {

    run(0);
    return 0;
}