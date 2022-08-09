#include <iostream>
using namespace std;

int main()
{
	char a, b, c;
	cin >> a >> b >> c;

	char* p, * g, * h;

	p = &a;
	g = &b;
	h = &c;

	if (*p >= *g && *p >= *h) cout << *p;
	else if (*g >= *p && *g >= *h) cout << *g;
	else if (*h >= *p && *h >= *g) cout << *h;

	return 0;
}