#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;


/*���� Ǯ��

*/

typedef struct {
	int what_time;
	int what_N;
	int what_M;
}Node;

int arr_t[1000];
int arr_a[9];
int arr_b[9];
queue<Node> q;
int main()
{
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
		int tccase;
		cin >> tccase;
		int N;   // ���� â���� ����
		cin >> N;
		int M;  // ���� û���� ����
		cin >> M;
		int K;  //���� ����Ҹ� �湮�� ���� �� 
		cin >> K;
		int A1;  // ������ �ΰ� ���� �̿��� ���� â����ȣ A�� ����â�� B
		cin >> A1;
		int A2;
		cin >> A2;

		for (int i = 0; i < N; i++)
		{
			int a;  // i��° ���� â���� ������ �����ϴ� �� �ɸ��� �ð� ai�� N��
			cin >> a;
			arr_a[i] = a;
		}

		for (int i = 0; i < M; i++)
		{
			int b;  // j��° ���� â���� ������ �����ϴ� �� �ɸ��� �ð� bj�� M��
			cin >> b;
			arr_b[i] = b;
		}

		//k��° ���� ���� ����Ҹ� �湮�ϴ� �ð� tk�� ������� K��
		for (int i = 0; i < K; i++)
		{
			int t;
			cin >> t;
			arr_t[i] = t;
		}

		for (int i = 0; i < K; i++)
		{
			q.push({ arr_t[i], -1 ,-1 });
		}

		while (1)
		{
			Node now = q.front();
			q.pop();


		}






	}
}