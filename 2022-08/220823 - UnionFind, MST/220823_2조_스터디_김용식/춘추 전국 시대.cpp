#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Val;
int Arr[100];
int parent[100] = { 0 };
int sum = 0;
int dat[100] = { 0 };
int Find(int now) {
	if (parent[now] == now) return now;
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}


void Union(int A, int B) {
	sum = 0;
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	if (dat[pA] == 0) {
		sum += Val[pA];
		dat[pA] = 1;
	}
	if (dat[pB] == 0) {
		sum += Val[pB];
		dat[pB] = 1;
	}
	
	parent[pB] = pA;
	if (Val[pA] == -2134567890 && Val[pB] == -2134567890)return;
	Arr[pA] += Arr[pB]+sum;
	//if(Arr[pA]+=Arr[pB] + sum == )
	int aoll=-2134567890+(-2134567890);
	//Arr[pB] = sum;

}


int main() {
	//freopen_s(new FILE *, "input.txt", "r", stdin);

	for (int i = 0; i < 100; i++) {
		parent[i] = i;
	}

	int Nation;
	cin >> Nation;
	
	for (int i = 0; i < Nation; i++) {
		int temp;
		cin >> temp;
		Val.push_back(temp);
	}

	int Situation;
	cin >> Situation;
	
	int sum;

	for (int i = 0; i < Situation; i++) {
		string AorW;
		char N1, N2;
		cin >> AorW;
		cin >> N1 >> N2;
		sum = 0;
		if (AorW == "alliance") {
			Union(N1-'A', N2-'A');
		}else if (AorW == "war") {
			if (Arr[Find(N1 - 'A')] > Arr[Find(N2 - 'A')]) {
				for (int i = 0; i < Val.size(); i++) {
					if (parent[i] == Find(N2 - 'A')) {
						Val[i] = -2134567890;
					}
				}
			}else if (Arr[Find(N1 - 'A')] < Arr[Find(N2 - 'A')]) {
				for (int i = 0; i < Val.size(); i++) {
					if (parent[i] == Find(N1 - 'A')) {
						Val[i] = -2134567890;
					}
				}
				//A 국가 없애
			}else if (Arr[Find(N1 - 'A')] == Arr[Find(N2 - 'A')]) {
				if (Arr[Find(N1 - 'A')] == 0) {
					if (Val[N2-'A'] > Val[N1-'A']) {
						Val[N1-'A'] = -2134567890;
					}
					else {
						Val[N2-'A'] = -2134567890;
					}
					continue;
					}

				for (int i = 0; i < Val.size(); i++) {
					if (parent[i] == Find(N1 - 'A') || parent[i] == Find(N2-'A')) {
						Val[i] = -2134567890;
					}
				}
			}
		}
	}
	int cnt = 0;
	int abc = Find('S' - 'A');
	int aaa = 2;
	for (int i = 0; i < Val.size(); i++) {
		if ((Val[i] == -2134567890) && (Val[Find(i)]!= -2134567890)) {
			cnt++;
		}
		if (Val[i] != -2134567890) {
			cnt++;
		}
	}
	cout << cnt;

	//0이아닌 국가를 출력하라.


	return 0;
