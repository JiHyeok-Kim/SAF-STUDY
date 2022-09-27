#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int tc;
	for (int testcase = 0; testcase < tc; testcase++)
	{
		int P;
		int Q;
		int R;
		int S;
		int W;
		cin >> P >> Q >> R >> S >> W;
		if (W < R)
		{
			cout <<'#' <<testcase+1<<' ' << Q << '\n';
		}
		else if (W > R)
		{
			cout << '#' << testcase + 1 << ' ' << Q + (W - R)S << '\n';
		}
	}



	return 0;
}