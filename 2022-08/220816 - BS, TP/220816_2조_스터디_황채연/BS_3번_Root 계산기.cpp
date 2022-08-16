#include <iostream>
using namespace std;

int n;
void bs(int sp, int ep) {
	int last = -1;
	while (sp <= ep) {
		int mid = (sp + ep) / 2;
		if (mid == n) {
			last = mid;
			break;
		}

		if (mid*mid > n) {
			ep = mid - 1;
		}
		if (mid*mid < n) {
			last = mid;
			sp = mid + 1;
		}
	}

	cout << last;
	return;
}

int main()
{
	cin >> n;
	bs(1, 4000);
	return 0;
}