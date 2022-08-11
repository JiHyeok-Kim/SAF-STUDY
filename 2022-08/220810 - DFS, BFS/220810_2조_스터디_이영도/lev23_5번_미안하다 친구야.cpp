#include <iostream>

#include <string>
using namespace std;

string name = "EWABC";

int via[10];
char path[10];

void run(int level)
{
    if (level == 4) {
        cout << path << endl;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (via[i] == 0) {
            via[i] = 1;
            path[level] = name[i];
            run(level + 1);
            path[level] = 0;
            via[i] = 0;
        }
    }
}

int main()
{
    char except;
    cin >> except;

    //제외시킬 친구를 via에 미리 체크
    for (int i = 0; i < 5; i++) {
        if (name[i] == except) {
            via[i] = 1;
        }
    }

    run(0);

    return 0;
}
