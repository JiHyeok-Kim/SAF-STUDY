#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string input;
string answer;
string main_answer;
int main()
{
	int a, b, c;
	cin >> input;
	cin >> a >> b >> c;

	answer = input.substr(a, b - a + 1);
	for (int i = 0; i < c; i++)
	{
		main_answer += answer;
	}
	cout << main_answer;
}