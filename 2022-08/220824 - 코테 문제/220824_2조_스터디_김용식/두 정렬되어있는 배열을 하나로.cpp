#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int Arr[4];
int Arr2[4];
vector<int> result;
int main() {
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 4; i++) {
		cin >> Arr[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> Arr2[i];
	}

	int A = 0;
	int B = 0;
	
	while (1) {
		if (A > 3) {
			for (int i = B; i < 4; i++) {
				result.push_back(Arr2[i]);
			}
			break;
		}
		else if (B > 3) {
			for (int i = A; i < 4; i++) {
				result.push_back(Arr[i]);
			}
			break;
		}
	
		if (Arr[A] >= Arr2[B]) {
			result.push_back(Arr2[B]);
			B++;
		}
		else if (Arr[A] < Arr2[B]) {
			result.push_back(Arr[A]);
			A++;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<<" ";
	}

	return 0;
}