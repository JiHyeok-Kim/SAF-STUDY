#include<iostream>
#include<vector>
#include<queue>



using namespace std;

struct Node {
	string domain;
	string id;
	string com;

};
int cnt = 0;
int main() {
	string mail;

	cin >> mail;
	Node now;

	for (int i = 0; i < mail.size(); i++)
	{
		if (mail[i] != '@' && cnt == 0)
		{
			now.id += mail[i];
		}
		else if (mail[i] == '@' && cnt == 0)
		{
			cout << "[#" << now.id << ']' << ' ';
			cnt++;
			now.id = "";
			continue;
		}


		if (mail[i] != '.' && cnt == 1)
		{
			now.domain += mail[i];
		}
		else if (mail[i] == '.' && cnt == 1)
		{
			cout << now.domain << '\n';
			cnt++;
			now.domain = "";
			continue;
		}

		if (mail[i] != '|' && cnt == 2)
		{
			now.com += mail[i];
		}
		else if (mail[i] == '|' && cnt == 2)
		{
			cnt = 0;
		}

		if (i + 1 > mail.size() && cnt == 2)
		{
			return 0;
		}
	}

}