#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int n, m;

char table[50][50];

int color_Num[50][3]; // 각 행마다 현재 존재하는 색의 개수 표시


// N 행 M 열 . 각 칸은 흰색, 파란색, 빨간색 
// 위에서 몇줄 (한줄이상) 모두흰색 
// 다음 몇줄 (한줄이상) 모두 파란색
// 나머지 (한줄이상) 모두 빨간색 

struct Color {
	int r; 
	int cnt; 
	char color;
};

int min_cnt = 100000000;

int Search() {

	queue<Color> q;
	q.push({ 1,color_Num[1][0], 'W' });
	q.push({ 1,color_Num[1][1], 'B' });

	while (!q.empty()) {
		int row = q.front().r;
		int cnt = q.front().cnt;
		char color = q.front().color;
		q.pop();
	
		if (row == n - 1) { // 맨 마지막줄은 어차피 모두 빨간색이기때문에 확인할 필요 없다. 
			if (color == 'W')	continue; // 모든 칸을 색칠 했을 경우 파란색이 없는 경우 
			else   min_cnt = min(min_cnt, cnt);
			continue;
		}

		if (color == 'W') { // 이전 줄이 흰색일 경우 가능한 경우 2가지 ( 흰색, 파란색 )
			q.push({ row + 1,cnt + color_Num[row + 1][0], 'W' });
			q.push({ row + 1, cnt + color_Num[row + 1][1], 'B' });
		}
		else if (color == 'B') { // 이전 줄이 파란색일 경우 가능한 경우 2가지 ( 파란색, 빨간색 )
			q.push({ row + 1, cnt + color_Num[row + 1][1], 'B' });
			q.push({ row + 1, cnt + color_Num[row + 1][2], 'R' });
		}
		else if (color == 'R') { // 이전 줄이 빨간색일 경우 가능한 경우 1가지 ( 빨간색 )
			q.push({ row + 1, cnt + color_Num[row + 1][2], 'R' });
		}
	}

	return min_cnt;
}


int main() {

	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; 
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		int result = 0; 
		min_cnt = 100000000;
		cin >> n >> m;

		memset(color_Num, 0, sizeof(color_Num));

		for (int i = 0; i < n; i++) {
			string in_str;
			int w_cnt = 0, b_cnt = 0, r_cnt = 0;
			cin >> in_str;
			for (int j = 0; j < in_str.size(); j++) {
				table[i][j] = in_str[j];

				//// 첫째줄, 마지막줄은 흰색과 빨간색으로 모두 바꿔줍니다. 
				if (i == 0 && table[i][j] != 'W') {
					table[i][j] = 'W';
					result++; // 바꾼 횟수 증가
				}
				else if (i == n - 1 && table[i][j] != 'R') {
					table[i][j] = 'R';
					result++; // 바꾼 횟수 증가
				}

				if (table[i][j] == 'W')	w_cnt++;
				else if (table[i][j] == 'B') b_cnt++;
				else if (table[i][j] == 'R')	r_cnt++;
			}
            // 2차원 배열에 각 색을 칠하기 위해 칠해야 하는 칸의 갯수 저장 
			color_Num[i][0] = m-w_cnt;
			color_Num[i][1] = m-b_cnt; 
			color_Num[i][2] = m-r_cnt;
		} // 테이블 정보 저장 

		cout << "#" << k << " " << result + Search() << endl; // 첫줄과 마지막 줄을 바꾼 횟수와 최소 횟수를 더해서 출력
	
	}
}
