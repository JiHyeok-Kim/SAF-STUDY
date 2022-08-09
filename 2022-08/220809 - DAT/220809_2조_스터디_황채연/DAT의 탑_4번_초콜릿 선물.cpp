#include <iostream>
#include <string>
using namespace std;

string in;
int cnt[150];
int main()
{
	cin >> in;
	for (int i = 0; i < in.size(); ++i) {
		cnt[in[i]]++;
	}

	for (int i = 0; i < 150; ++i) {
		if (cnt[i] == 0) continue;
		cout << char(i);
	}
	return 0;
}