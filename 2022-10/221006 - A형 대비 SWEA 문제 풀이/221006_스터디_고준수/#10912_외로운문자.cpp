#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;


/*문제 풀이

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
		int N;   // 접수 창구의 개수
		cin >> N;
		int M;  // 정비 청구의 개수
		cin >> M;
		int K;  //차량 정비소를 방문한 고객의 수 
		cin >> K;
		int A1;  // 지갑을 두고간 고객이 이용한 접수 창구번호 A와 정비창구 B
		cin >> A1;
		int A2;
		cin >> A2;

		for (int i = 0; i < N; i++)
		{
			int a;  // i번째 접수 창구가 고장을 접수하는 데 걸리는 시간 ai가 N개
			cin >> a;
			arr_a[i] = a;
		}

		for (int i = 0; i < M; i++)
		{
			int b;  // j번째 정비 창구가 차량을 정비하는 데 걸리는 시간 bj가 M개
			cin >> b;
			arr_b[i] = b;
		}

		//k번째 고객이 차량 정비소를 방문하는 시간 tk가 순서대로 K개
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