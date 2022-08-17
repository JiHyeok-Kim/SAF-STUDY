#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int arr_s[51] = { 0 };
int arr_o[51] = { 0 };
int main() 
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> arr_s[i];
		cin >> arr_o[i];
	}

	sort(arr_s, arr_s + M);
	sort(arr_o, arr_o + M);

	// 낱개가 세트보다 더 쌀때
	if (arr_o[0] * 6 <= arr_s[0]) cout << arr_o[0] * N;

	// 세트가 더 쌀때
	else
	{
		int price = 0;
		int tmp = 0;
		price = (N / 6)*arr_s[0];
		tmp = N % 6;
		//낱개가 안남을때
		if (tmp == 0)cout << price;
		
		//낱개가 남을때
		else
		{
			if (arr_o[0] * tmp < arr_s[0])cout << price + (arr_o[0] * tmp);
			else cout << price + arr_s[0];
		}


	}


}