#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{
		int P; //L당 P원
		int Q; //기본 요금
		int R; //월간 사용량 R L 이하
		int S; //초고하면 L당 S원
		int W; // 월간 내 사용량
		cin >> P >> Q >> R >> S >> W;
		int A_com = W * P;
		int B_com;

		if (W <= R)
		{
			B_com = Q;
		}
		else if (W > R)
		{
			B_com = Q + (W - R)*S;
		}

		if (A_com > B_com)
		{
			cout << '#' << testcase + 1 << ' ' << B_com << '\n';
		}
		else if (A_com <= B_com)
		{
			cout << '#' << testcase + 1 << ' ' << A_com << '\n';
		}


		/*if (W < R)
		{
			cout << '#' << testcase + 1 << ' ' << Q << '\n';
		}
		else if (W > R)
		{
			cout << '#' << testcase + 1 << ' ' << Q + (W - R)S << '\n';
		}*/
		
	}



	return 0;
}