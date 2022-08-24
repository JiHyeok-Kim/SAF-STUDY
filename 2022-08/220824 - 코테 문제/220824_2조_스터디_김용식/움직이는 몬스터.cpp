#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char Arr[4][3];
int dx[5] = { 1,0,-1,0,1 };
int dy[5] = { 0,1,0,-1,0 };
int monsterMove = 0;
void monster(int y, int x) {
		int ny = y + dy[monsterMove];
		int nx = x + dx[monsterMove];
		if (ny < 0 || nx < 0 || nx >= 3 || ny >= 5)return;
		if (Arr[ny][nx] != '_') return;
		char temp = Arr[ny][nx];
		Arr[ny][nx] = Arr[y][x];
		Arr[y][x] = temp;
	
	return;
}

int main(){
	//FILE* freinput = freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Arr[i][j];
		}
	}
		
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (Arr[i][j] != '_' && Arr[i][j] != '#') {
				monster(i, j);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Arr[i][j];
		}cout << '\n';
	}

	return 0;
}