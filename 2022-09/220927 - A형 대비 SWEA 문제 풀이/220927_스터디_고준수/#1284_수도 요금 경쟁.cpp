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
		int P; //L�� P��
		int Q; //�⺻ ���
		int R; //���� ��뷮 R L ����
		int S; //�ʰ��ϸ� L�� S��
		int W; // ���� �� ��뷮
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