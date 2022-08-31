#include<iostream>

using namespace std;



int arr[11] = { 0 };
int main()
{
	int num;
	int number;
	int type;
	cin >> type;
	cin >> num;
	int cnt = 0;
	if (type == 1)
	{
		for (int i = 1; i < num + 1; i++)
		{
			cin >> number;
			arr[number]++;
		}

		for (int i = 1; i < 10; i++)
		{
			cout << i << ":" << arr[i] << "개" << '\n';
		}
	}

	else if (type == 2)
	{
		for (int i = 1; i < num + 1; i++)
		{
			cin >> number;
			arr[number]++;
		}
		for (int i = 1; i < 10; i++)
		{
			if (arr[i] > 1)
			{
				cout << "중복발견";
				cnt++;
				break;
			}
		}
		if (cnt == 0)
		{
			cout << "중복없음";
		}
	}

}