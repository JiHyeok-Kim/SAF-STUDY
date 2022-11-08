#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int flag,len, ans;
string frog;
int c, r, o, a, k;
queue<int> q;

void finding() {
	c = frog.find('c',c + 1);
	r = frog.find('r',r + 1);
	o = frog.find('o',o + 1);
	a = frog.find('a',a + 1);
	k = frog.find('k',k + 1);
	q.push(k);
	if (c < q.front()) ans++;
	else (q.pop());
}


void solve()
{
	while (!q.empty()) {
		q.pop();
	}
	c = r = o = a = k = -1;
	flag = 0;
	ans = 0;
	cin >> frog;
	len = frog.size();
	if (len % 5 != 0 || frog[0] != 'c') {
		ans = -1; return;
	}
	for(int i = 0; i < len/5; i++)
	{
		finding();
		if (!(c < r && r < o && o < a && a < k)) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		ans = -1;
		return;
	}
}


int main()
{	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}