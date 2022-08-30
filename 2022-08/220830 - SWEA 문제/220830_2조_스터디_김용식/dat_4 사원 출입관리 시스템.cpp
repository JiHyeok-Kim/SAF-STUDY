#include <iostream>
#include <string>
#include <vector>
using namespace std;
int Dat[100000] = { 0 };

struct Node {
	int num;
	string name;

};
vector<Node> v;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int Tc;
	cin >> Tc;
	for (int test = 0; test < Tc; test++) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			int a;
			string b;
			cin >> a >> b;
			if (Dat[a] == 1||Dat[a]==2) {
				cout << a << " " << "ERROR" << '\n';
			}
			else {
				Dat[a] = 1;
				cout << a << " " << "OK" << '\n';
				v.push_back({ a,b });
			}
		}
		else if (temp == 2) {
			int p;
			cin >> p;
			if (Dat[p] == 0) {
				cout << p << " " << "ERROR" << '\n';
			}
			else if (Dat[p] == 1) {
				int idx = 0;
				for (int i = 0; i < v.size(); i++) {
					if (v[i].num == p) {
						idx = i;
						break;
					}
				}
				cout << p << " " << v[idx].name << " " << "ENTER" << '\n';
				Dat[p] =2;

			}
			else if (Dat[p] == 2) {
				int idx = 0;
				for (int i = 0; i < v.size(); i++) {
					if (v[i].num == p) {
						idx = i;
						break;
					}
				}
				cout << p << " " << v[idx].name << " " << "EXIT" << '\n';
				Dat[p] = 1;
			}
			
		}
		
	}

	return 0;
}