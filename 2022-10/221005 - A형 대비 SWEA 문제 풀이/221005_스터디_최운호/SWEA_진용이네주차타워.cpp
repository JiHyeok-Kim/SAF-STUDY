#include <iostream>
#include <queue>
using namespace std;

struct park {
	int cost;
	int state;
};

struct car {
	int w;
	int area;
};

int n, m;
park info[101];
car c[2001];
int result;

queue<int> wait;
int used;

void pIn(int num)
{
	if (used == n) {
		wait.push(num);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (info[i].state == 0) {
			info[i].state = 1;
			c[num].area = i;
			result += c[num].w * info[i].cost;
			used++;
			break;
		}
	}
}

void pOut(int num)
{
	info[c[num].area].state = 0;
	used--;
}

void waiting() {
	if (used == n) return;

	int cNum = wait.front();
	wait.pop();

	for (int i = 1; i <= n; i++) {
		if (info[i].state == 0) {
			info[i].state = 1;
			c[cNum].area = i;
			result += c[cNum].w * info[i].cost;
			used++;
			break;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		result = 0;
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			info[i].cost = tmp;
			info[i].state = 0;
		}
		for (int i = 1; i <= m; i++) {
			int tmp;
			cin >> tmp;
			c[i].w = tmp;
			c[i].area = -1;
		}

		for (int i = 0; i < 2 * m; i++) {
			int p;
			cin >> p;
			if (wait.size() != 0) waiting();
			if (p > 0) pIn(p);
			else if (p < 0) pOut(abs(p));
		}

		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}