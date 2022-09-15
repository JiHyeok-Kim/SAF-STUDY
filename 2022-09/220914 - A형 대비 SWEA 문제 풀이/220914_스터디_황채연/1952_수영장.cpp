#include <iostream>
#include <vector>
using namespace std;
 
int T;
int coin[4], month[12], temp[12];
typedef struct {
    int idx;
    int type;
}MONTH;
vector<MONTH> pick;
int mini;
 
int checkDate() {
    for (int i = 0; i < 12; ++i) {
        if (temp[i] == 0) continue;
        return 1;
    }
    return 0;
}
 
int calcPick() {
    int sum = 0;
    for (int i = 0; i < pick.size(); ++i) {
        if (pick[i].type == 0) {
            int one_day_cost = coin[0] * month[pick[i].idx];
            int month_cost = coin[1];
            if (one_day_cost > month_cost) {
                sum += month_cost;
            }
            else sum += one_day_cost;
        }
        if (pick[i].type == 1) {
            sum += coin[2];
        }
    }
    return sum;
}
 
void DFS(int sp) {
    if (checkDate() == 0) {
        int cost = calcPick();
        if (mini > cost) mini = cost;
        return;
    }
 
    for (int type = 0; type < 2; ++type) {
        for (int i = sp; i < 12; ++i) {
            if (temp[i] == 0) continue;
            if (type == 0) {
                pick.push_back({i, type});
                temp[i] = 0;
                DFS(i + 1);
                temp[i] = month[i];
                pick.pop_back();
            }
            if (type == 1) {
                pick.push_back({i, type});
                int flag = 0;
                for (int j = i; j < i + 3; ++j) {
                    if (j >= 12) {
                        flag = 1;
                        break;
                    }
                    temp[j] = 0;
                }
                if (flag == 0) DFS(i + 3);
                else if (flag == 1) DFS(11);
 
                for (int j = i; j < i + 3; ++j) {
                    if (j >= 12) break;
                    temp[j] = month[j];
                }
                pick.pop_back();
            }
        }
    }
}
 
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        for (int i = 0; i < 4; ++i) {
            cin >> coin[i];
        }
        for (int i = 0; i < 12; ++i) {
            cin >> month[i];
            temp[i] = month[i];
        }
 
        mini = coin[3]; // 1년 값으로 세팅
        DFS(0);
        cout << "#" << tc << " " << mini << "\n";
    }
    return 0;
}