#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <valarray>
#include <string>
using namespace std;



int used[10001];
string str_name[10001];
string str_used[10001];
int used_cnt[10001] = { 0 };
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int cmd, id;
		string name;

		cin >> cmd;

		if (cmd == 1)
		{
			cin >> id >> name;
			if (used[id] == 0)
			{
				used[id] = 1;
				str_name[id] = name;
				cout << id << " " << "OK" << '\n';
			}
			else if (used[id] != 0)
			{
				cout << id << " " << "ERROR" << '\n';
			}
		}



		else if (cmd == 2)
		{
			cin >> id;
			if (used[id] == 0)
			{
				cout << id << " " << "ERROR" << '\n';
			}
			else if (used_cnt[id] == 0)
			{
				cout << id << " " << str_name[id] << " " << "ENTER" << '\n';
				used_cnt[id]++;
			}
			else if (used_cnt[id] == 1)
			{
				cout << id << " " << str_name[id] << " " << "EXIT" << '\n';
				used_cnt[id] = 0;
			}





		}
	}


}