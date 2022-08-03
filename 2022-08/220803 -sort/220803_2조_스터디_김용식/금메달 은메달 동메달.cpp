#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
	string name;
	int score;
	int order;
};

//t랑 v가 무슨 값 이 들어오는지는 알 필요가 없어요.
//t에 어떤값 들어있음
//v에 어떤값 들어있음

//t를 기준으로 더 앞쪽에 있어야하는 값이라면? 1 리턴
//아니면 0 리턴

//"비교기"
//기준값 필요없어없어없어없어
bool compare(Node t, Node v) {
	if (t.score > v.score) return 1;
	if (t.score < v.score) return 0;

	if (t.order > v.order) return 1;
	return 0;
}

int main() {
	int num;
	cin >> num;

	vector<Node> alist;

	for (int i = 0; i < num; i++) {
		string name;
		int score;

		cin >> name >> score;
		alist.push_back({ name, score,i });

		sort(alist.begin(), alist.end(), compare);

		for (int j = 0; j < alist.size(); j++) {
			if (j == 3) break;
			cout << alist[j].name << " ";
		}
		cout << endl;
	}


	return 0;
}