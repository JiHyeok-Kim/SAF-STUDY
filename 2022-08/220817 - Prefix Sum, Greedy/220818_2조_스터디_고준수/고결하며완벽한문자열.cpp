//a형 벽돌깨기
#include <iostream>
#include <queue>
using namespace std;


//전역변수
int N, W, H;
int map[20][20];
int sum_x[20] = { 0 };
int max1 = -1;
int max_idx = 0;
int used[20][20] = { 0 };
vector<int> gravity_arr;



void init()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			used[i][j] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		sum_x[i] = 0;
	}
	max_idx = 0;
	max1 = -1;
}


void print()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void gravity()
{
	for (int j = 0; j < W; j++)
	{
		for (int i = H - 1; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				gravity_arr.push_back(map[i][j]);
				map[i][j] = 0;

			}
		}
		for (int i = 0; i < gravity_arr.size(); i++)
		{
			map[H - 1 - i][j] = gravity_arr[i];
		}
		gravity_arr.clear();


	}

}

int search_max()
{
	init();
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (map[j][i] == 0)continue;
			int val = map[j][i] - 1;
			for (int k = i - val; k <= i + val; k++)
			{
				if (k < 0 || k >= W) continue;
				sum_x[i] += map[j][k];
			}
		}
	}
	for (int i = 0; i < W; i++)
	{
		if (sum_x[i] > max1)
		{
			max1 = sum_x[i];
			max_idx = i;
		}
	}
	return max_idx;
}

typedef struct {
	int y;
	int x;

}Node;

queue<Node> q;
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };
void bfs(int y, int x)
{
	q.push({ y,x });
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		used[now.y][now.x] = 1;
		int val = map[now.y][now.x] - 1;
		map[now.y][now.x] = 0;
		if (val == 0) continue;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= val; j++)
			{

				int ny = now.y + directY[i] * j;
				int nx = now.x + directX[i] * j;
				if (ny<0 || nx <0 || ny >H || nx > W) continue;
				if (map[ny][nx] == 0) continue;

				q.push({ ny,nx });
			}
		}
	}

}










/*for (int j = 0; j < H; j++)
{
	if (map[j][popidx] == 0) continue;

	int val = map[j][popidx] - 1;
	for (int z = j; z <= j + val; z++)
	{


		for (int k = popidx - val; k <= popidx + val; k++)
		{
			if (z<0 || z >= H ||k < 0 || k >= W) continue;
			map[z][k] = 0;
		}
	}
	break;
}*/



/*for (int j = 0; j < H; j++)
{
	if (map[j][popidx] == 0)continue;
	int val = map[j][popidx] - 1;
	for (int k = popidx - val; k <= popidx + val; k++)
	{
		if (k < 0 || k >= W) continue;
		map[j][k] = 0;
	}
}*/


int main()
{
	//int testcase;
	//cin >> testcase;


	cin >> N >> H >> W;
	//testcase =5
	/*for (int tc = 0; tc < testcase; tc++)
	{*/
	//y축
	for (int i = 0; i < H; i++)
	{   // x축
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}
	/*}*/
	/*for (int i = 0; i < N; i++)
	{
		pop(search_max());
		print()
		gravity();
		print();
	}*/

	cout << "#1" << '\n';
	int idx_y = 0;
	int popidx = search_max();
	for (int i = 0; i < H; i++)
	{
		if (map[i][popidx] != 0)
		{
			idx_y = i;
			break;
		}

	}
	//map[idx_y][popidx] = 0;
	bfs(idx_y, popidx);
	cout << "#1" << '\n';
	print();
	cout << "#1" << '\n';
	gravity();
	print();

	cout << '\n';
	cout << "#2" << '\n';
	idx_y = 0;
	popidx = search_max();
	for (int i = 0; i < H; i++)
	{
		if (map[i][popidx] != 0)
		{
			idx_y = i;
			break;
		}

	}
	//map[idx_y][popidx] = 0;
	bfs(idx_y, popidx);
	cout << "#2" << '\n';
	print();
	gravity();
	cout << "#2" << '\n';
	print();




	idx_y = 0;
	popidx = search_max();
	cout << popidx << '\n';
	for (int i = 0; i < H; i++)
	{
		if (map[i][popidx] != 0)
		{
			idx_y = i;
			break;
		}

	}

	cout << "#2" << '\n';
	map[idx_y][popidx] = 0;
	bfs(idx_y, popidx);
	cout << "#2" << '\n';
	print();
	gravity();

	cout << "#2" << '\n';
	print();


}