#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int pay;
	int full;
};

int N, M;
vector<Node> R;
vector<int> W;
queue<int> q;
queue<int> wait;

void init()
{
	R.clear();
	W.clear();
	W.push_back(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		R.push_back({ n, 0 });
	}
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		W.push_back(n);
	}
	for (int i = 0; i < M * 2; i++)
	{
		int n;
		cin >> n;
		q.push(n);
	}

	return;
}

int income()
{
	int sum = 0;
	int flag = 0;
	int flagW = 0;
	while (!q.empty() + !wait.empty())
	{
		int car;
		if (flagW == 1 && flag != N) {
			car = wait.front();
			wait.pop();
			if (wait.empty()) flagW = 0;
		}
		else{
			car = q.front();
			q.pop();
		}

		if (car > 0) {
			if (flag == N) wait.push(car);
			else {
				for (int i = 0; i < R.size(); i++) {
					if (R[i].full == 0) {
						flag++;
						R[i].full = car;
						sum += W[car] * R[i].pay;
						break;
					}
				}
			}

		}
		else {
			for (int i = 0; i < R.size(); i++) {
				if (R[i].full == abs(car)) {
					flag--;
					R[i].full = 0;
					break;
				}
			}
			if (!wait.empty()) flagW = 1;
		}

	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		int ans = income();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}