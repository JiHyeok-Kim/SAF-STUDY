#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N, M;

int graph[51][51];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> T;
	for(int t = 1; t<= T; ++t){
		cin >> N >> M;
		for (int a = 0; a < M; ++a) {
			int n1, n2;
			cin >> n1 >> n2;
			graph[n1][n2] = 1;
			graph[n2][n1] = 1;
		}
		int ans = 0;
		for (int a = 1; a <= N; ++a) {
			for (int b = a+1; b <= N; ++b) {
				if (graph[a][b] == 1) {
					for (int c = b + 1; c <= N; ++c) {
						if (graph[a][c] == 1 && graph[b][c] == 1) {
							++ans;
						}
					}
				}
			}
		}
		cout << "#"<<t<< " "<<ans << "\n";
		memset(graph, 0, sizeof(graph));
	}

}
