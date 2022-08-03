#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
typedef struct {
	string name;
	int score;
	int idx;
}PERSON;
vector<PERSON> v;

bool compare(PERSON t, PERSON v) {
	if (t.score > v.score) return 1;
	if (t.score < v.score) return 0;
	if (t.score == v.score) {
		if (t.idx > v.idx) return 1;
		else return 0;
	}
}

int main()
{
	cin >> n;
	int start = 1;
	for (int i = 0; i < n; ++i) {
		string t_name;
		int t_score;
		cin >> t_name >> t_score;
		v.push_back({ t_name, t_score, i });

		sort(v.begin(), v.end(), compare);
		if (start <= 3) {
			for (int j = 0; j < start; ++j) {
				cout << v[j].name << " ";
			}
			cout << "\n";
			start++;
		}
		else {
			for (int j = 0; j < 3; ++j) {
				cout << v[j].name << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}