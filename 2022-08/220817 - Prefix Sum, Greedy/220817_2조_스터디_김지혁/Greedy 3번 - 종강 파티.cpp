#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arrSet[50];
int arrOne[50];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> arrSet[i] >> arrOne[i];
	}
	sort(arrSet, arrSet + M);
	sort(arrOne, arrOne + M);
	if (arrSet[0] > arrOne[0] * 6)
	{
		cout << N * arrOne[0]; return 0;
	}
	int q = N / 6;
	int sum = q * arrSet[0];
	int r = N % 6;
	if (r * arrOne[0] >= arrSet[0]) sum += arrSet[0];
	else
	{
		sum += r * arrOne[0];
	}

	cout << sum;

	return 0;
}