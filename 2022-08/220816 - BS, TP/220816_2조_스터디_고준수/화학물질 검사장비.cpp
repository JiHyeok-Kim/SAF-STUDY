#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string input;
string new_input;
double pass_cnt = 0;
double fail_cnt = 0;
int ret = 0;
int main()
{
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (int(input[i]) >= 65 && int(input[i]) <= 90)
		{
			new_input += int(input[i] + 32);
		}
		else
		{
			new_input += input[i];
		}
	}
	int idx = 0;
	while (ret != -1 && idx <= new_input.size())
	{
		ret = new_input.find("pass", idx);
		if (ret != -1)
		{
			pass_cnt++;
			idx = ret + 4;
		}

	}
	idx = 0;
	ret = 0;

	while (ret != -1 && idx <= new_input.size())
	{
		ret = new_input.find("fail", idx);
		if (ret != -1)
		{
			fail_cnt++;
			idx = ret + 4;
		}
	}
	double arr = pass_cnt / (pass_cnt + fail_cnt);
	cout << int(arr * 100) << '%';
}