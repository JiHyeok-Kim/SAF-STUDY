#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node {
    int x;
    int y;
};

int T, N;
int map[25][25] = { 0, };
int used[25][25] = { 0, };
int check[101] = { 0, };

int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

int maxi = 0;

int start_x, start_y;
int turn = 0;
int blockCnt = 1;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void findDfs(Node now,int P)
{
    
    if (turn == 4)return;
    
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)//계속 간다.
        {
            int nx = now.x + dx[P];
            int ny = now.y + dy[P];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
            if (nx == start_x && ny == start_y)//첫번째 좌표로 돌아왔을때
            {
                if (blockCnt > maxi)
                {
                    if (blockCnt != 1)maxi = blockCnt;
                    return;
                }
            }
            if (used[nx][ny] == 1)continue;
            if (check[map[nx][ny]] == 1)continue;
            
            used[nx][ny] = 1;
            check[map[nx][ny]] = 1;
            blockCnt++;
            findDfs({ nx,ny }, P);
            used[nx][ny] = 0;
            check[map[nx][ny]] = 0;
            blockCnt--;

        }
        else//꺾는다.
        {
            if (P + 1 == 4)continue;
            int nx = now.x + dx[P+1];
            int ny = now.y + dy[P+1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
            if (nx == start_x && ny == start_y)//첫번째 좌표로 돌아왔을때
            {
                if (blockCnt > maxi)
                {
                    if (blockCnt != 1)maxi = blockCnt;
                    return;
                }
            }
            if (used[nx][ny] == 1)continue;
            if (check[map[nx][ny]] == 1)continue;
            
            used[nx][ny] = 1;
            check[map[nx][ny]] = 1;
            blockCnt++;
            turn++;
            findDfs({ nx,ny }, P+1);
            turn--;
            used[nx][ny] = 0;
            check[map[nx][ny]] = 0;
            blockCnt--;
        }

    }

}

void clear()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            used[i][j] = 0;

    for (int i = 0; i < 101; i++)
        check[i] = 0;
}

int main()
{
    cin >> T;
    for (int tc = 1; tc < T + 1; tc++)
    {
        //디저트 개수 입력
        input();
        maxi = 0;
        //탐색
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                start_x = i;
                start_y = j; 
                turn = 0;
                blockCnt = 1;
                used[i][j] = 1;
                check[map[i][j]] = 1;
                findDfs({ i,j },0);
                used[i][j] = 0;
                check[map[i][j]] = 0;
            }
        }

        if (maxi != 0)cout << "#" << tc << " " << maxi << '\n';
        else cout << "#" << tc << " " << -1 << '\n';
    }

    int debug = 100;


}