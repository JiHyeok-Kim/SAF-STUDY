#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int H, W, num, dr, pin;
string ans;
string map[21];
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };
int ny, nx;
int QuestFlag;
int ansFlag;
struct Node {
	int y, x;
};
struct Coord {
	int y, x, dr, num;
};
Node now;
vector<Coord> used;
vector<Coord> Quest;
vector<Node> point;


void init() {
	num = 0;
	for (int i = 0; i < 21; i++) {
		map[i] = "";
	}
	used.clear();
	Quest.clear();
	point.clear();
}
void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		cin >> map[y];
	}
}
void Change(int nowY, int nowX, int dr) {
	if (dr == 0 && nowY == 0) {
		ny = H - 1;
	}
	else if (dr == 1 && nowY == H - 1) {
		ny = 0;
	}
	else if (dr == 2 && nowX == 0) {
		nx = W - 1;
	}
	else if (dr == 3 && nowX == W - 1) {
		nx = 0;
	}
	else {
		ny = nowY + ditY[dr];
		nx = nowX + ditX[dr];
	}
}
bool isUsed(Coord temp) {
	for (int i = 0; i < used.size(); i++) {
		if (used[i].y == temp.y && used[i].x == temp.x && used[i].dr == temp.dr && used[i].num == temp.num) {
			return 1;
		}
	}
	return 0;
}
bool QuestUsed(Coord temp) {
	if (Quest[0].y == temp.y && Quest[0].x == temp.x) return 1;
	for (int i = 0; i < Quest.size(); i++) {
		if (Quest[i].y == temp.y && Quest[i].x == temp.x && Quest[i].dr == temp.dr && Quest[i].num == temp.num) {
			return 1;
		}
	}
	return 0;
}
bool isPossible() {
	int flag = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == '@') {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (flag == 1) return 1;
	return 0;
}

bool isPoint(int yy, int xx) {
	for (int i = 0; i < point.size(); i++) {
		if (point[i].y == yy && point[i].x == xx) return 1;
	}
	return 0;
}


void goSearch(int dr)
{
	while (1) {
		if (ansFlag == 1) {
			ans = "YES";
			break;
		}
		now.y = ny;
		now.x = nx;
		if (isPoint(now.y, now.x)) return;
		Coord temp = { now.y, now.x, dr, num };
		if (QuestFlag == 1) {
			if (QuestUsed(temp)) {
				return;
			}
			Quest.push_back(temp);
		}
		
		if (isUsed(temp)) {
			ans = "NO";
			break;
		}
		used.push_back(temp);
		
		

		if (map[now.y][now.x] == '@') {
			ansFlag = 1;
			ans = "YES";
			break;
		}
		else if (map[now.y][now.x] == '^') {
			dr = 0;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == 'v') {
			dr = 1;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '<') {
			dr = 2;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '>') {
			dr = 3;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '_') {
			if (num == 0) dr = 3;
			else dr = 2;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '|') {
			if (num == 0) dr = 1;
			else dr = 0;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '?') {
			//무작위
			for (int i = 0; i < 4; i++) {
				int ty = now.y + ditY[i];
				int tx = now.x + ditX[i];
				if (ty < 0 || tx < 0 || ty >= H || tx >= W) continue;
				if (map[ty][tx] == '@') {
					ansFlag = 1;
					break;
				}
			}
			pin = dr;
			QuestFlag = 1;
			point.push_back({ now.y,now.x });
			for (int i = 0; i < 4; i++) {
				if (ansFlag == 1) break;

				Change(now.y, now.x, i);
				temp = { now.y, now.x, i, num };
				Quest.push_back(temp);
				goSearch(i);
				Quest.clear();
			}
			Quest.clear();
			QuestFlag = 0;

		}
		else if (map[now.y][now.x] == '.') {
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '+') {
			if (num == 15) num = 0;
			else num += 1;
			Change(now.y, now.x, dr);
		}
		else if (map[now.y][now.x] == '-') {
			if (num == 0) num = 15;
			else num -= 1;
			Change(now.y, now.x, dr);
		}
		else if ('0' <= map[now.y][now.x] && map[now.y][now.x] <= '9') {
			num = map[now.y][now.x] - '0';
			Change(now.y, now.x, dr);
		}

	}
}

void solve() {
	if (isPossible() == 0) {
		ans = "NO";
		return;
	};
	dr = 3;
	ny = nx = 0;
	QuestFlag = 0;
	ansFlag = 0;
	goSearch(dr);

}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
		//cout << ny << " " << nx;
	}

	return 0;
}