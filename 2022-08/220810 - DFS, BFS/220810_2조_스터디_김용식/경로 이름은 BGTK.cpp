#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[4] = {};
char name[5] = "BGTK";
int a;
void run(int lev) {
    if (lev == a) {
        cout << path << "\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        path[lev] =  name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main() {
    cin >> a;
    run(0);

    return 0;
}