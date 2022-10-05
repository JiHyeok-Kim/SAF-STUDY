#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <memory.h>
using namespace std;


int T;
int H, W,N;
char field[22][22];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
unordered_map<char, int> mp;
int tank_x;
int tank_y;
int arrow;
char convert[5] = { '^','>','v','<' };
void shoot() {
	for (int a = 1; ; ++a) {
		int nx = tank_x + mov[arrow][0]*a;
		int ny = tank_y + mov[arrow][1]*a;
		if (nx < 0 || nx >= H || ny < 0 || ny >= W) return;
		if (field[nx][ny] == '#') return;
		if (field[nx][ny] == '*') {
			field[nx][ny] = '.';
			return;
		}
	}	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	mp['^'] = 0;
	mp['>'] = 1;
	mp['v'] = 2;
	mp['<'] = 3;
	mp['U'] = 0;
	mp['R'] = 1;
	mp['D'] = 2;
	mp['L'] = 3;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> H >> W; 
		for (int h = 0; h < H; ++h) {
			string tmp;
			cin >> tmp;
			for (int w = 0; w < W; ++w) {
				field[h][w] = tmp[w];
				if (field[h][w] == '<' || field[h][w] == '>' || field[h][w] == '^' || field[h][w] == 'v') {
					tank_x = h;
					tank_y = w;
					arrow = mp[field[h][w]];
					field[h][w] = '.';
				}
			}
		}
		cin >> N;
		string command;
		cin >> command;
		for (int a = 0; a < N; ++a) {
			if (command[a] == 'S') {
				shoot();
			}
			else {
				arrow = mp[command[a]];
				int nx = tank_x + mov[arrow][0];
				int ny = tank_y + mov[arrow][1];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (field[nx][ny] == '.') {
					tank_x = nx;
					tank_y = ny;
				}
			}
		}
		field[tank_x][tank_y] = convert[arrow];
		cout << "#" << t << " ";
		for (int a = 0; a < H; ++a) {
			for (int b = 0; b < W; ++b) {
				cout << field[a][b];
			}
			cout << "\n";
		}
	}
	
	return 0;
}
