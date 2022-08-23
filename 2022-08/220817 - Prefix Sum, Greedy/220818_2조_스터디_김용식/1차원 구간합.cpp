#include <iostream>
using namespace std;
int Arr[100001];
int result[100001];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
	result[0] = Arr[0];
	
	for (int i = 1; i < N; i++) {
		result[i] = result[i - 1] + Arr[i];
	}
	int a = 2;

	for (int i = 0; i < M; i++) {
		int start, last;
		cin >> start >> last;
		if (start == 1) {
			cout << result[last-1]<<endl;
		}
		else {
			cout << result[last-1] - result[start - 2]<<endl;
		}
	}


	return 0;
}