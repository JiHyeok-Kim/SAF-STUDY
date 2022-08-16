//#include <iostream>
//#include <string>
//using namespace std;
//
//
//int arr[8][8];
//// floodfill
//
//int directY[4] = { -1,1,0,0 };
//int directX[4] = { 0,0,-1,1 };
//dy = ny + directY[y];
//dx = nx + directY[x];
//int cnt = 0;
//int to_y[100];
//int to_x[100];
//
//
//void run
//
//
//
//int main()
//{
//	int y, x;
//	for (int i = 0; i < y; i++)
//	{
//		for (int j = 0; j < x; j++)
//		{
//			cin >> arr[y][x];
//
//		}
//	}
//
//	for (int i = 0; i < y; i++)
//	{
//		for (int j = 0; j < x; j++)
//		{
//			if (arr[y][x] == 2)
//			{
//				to_y[cnt] = y;
//				to_x[cnt] = x;
//				cnt++;
//			}
//
//		}
//	}
//
//
//	
//	
//}

#include <iostream>

#include <queue>

#include <Windows.h>

using namespace std;

int map[10][10] = { 0 };
int dY[] = { -1, 0, 1, 0 };
int dX[] = { 0, 1, 0,-1 };

struct node {
    int y, x;
    int level;
};

void action() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    Sleep(1000);
}

int main() {
    queue<node> q;
    q.push({ 1,1,0 });
    q.push({ 6,6,0 });
    map[1][1] = 1;
    map[6][6] = 1;

    while (!q.empty()) {
        node now = q.front();
        q.pop();
        action();

        for (int i = 0; i < 4; i++) {
            int newY = now.y + dY[i];
            int newX = now.x + dX[i];

            if (map[newY][newX] == 1) continue;
            if (newY < 0 || newX < 0 || newY >= 10 || newX >= 10) continue;

            map[newY][newX] = 1;
            q.push({ newY, newX, now.level + 1 });
        }
    }
    return 0;
}