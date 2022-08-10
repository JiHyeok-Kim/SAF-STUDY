#include <iostream>
using namespace std;
char Arr[5];
int count123=0;
char path[10];
void run(int lev) {
	if (lev == 4) {
		count123++;
		/*cout << path << " "<<endl;*/
		return;
	}
	for (int i = 0; i < 4; i++) {
		path[lev]=Arr[i];
		if (lev >= 1 && (path[lev] == 'B' && path[lev - 1] == 'T') || (path[lev] == 'T' && path[lev - 1] == 'B'))continue;
		run(lev + 1);
		path[lev] = 0;
	}


}

int main() {
	cin >> Arr;
	run(0);
	cout << count123;
	return 0;
}