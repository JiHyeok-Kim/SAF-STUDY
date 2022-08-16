#include <iostream>
#include <string>
using namespace std;

int N;
string target;

void bs(int sp, int ep) {
	int last = -1;

	while (sp <= ep) {
		int mid = (sp + ep) / 2;
		if (target[mid] == '_') {
			ep = mid - 1;
		}
		else {
			last = mid;
			sp = mid + 1;
		}
	}

	last++;
	int perc = 100 * last / target.size();
	cout << perc << "%\n";
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> target;
		bs(0, target.size() - 1);
	}
	return 0;
}