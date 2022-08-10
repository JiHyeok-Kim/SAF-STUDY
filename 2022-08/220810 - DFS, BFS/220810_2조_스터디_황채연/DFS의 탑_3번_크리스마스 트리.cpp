#include <iostream>
#include <vector>
using namespace std;

int N;
typedef struct {
	int left;
	int right;
}NODE;
vector <vector<NODE>> v(1001);

void DFS3(int node) {
	if (v[node][0].left != -1) DFS3(v[node][0].left);
	if (v[node][0].right != -1) DFS3(v[node][0].right);
	cout << node << " ";

}
void DFS2(int node) {
	cout << node << " ";
	if (v[node][0].left != -1) DFS2(v[node][0].left);
	if (v[node][0].right != -1) DFS2(v[node][0].right);
}
void DFS1(int node) {
	if (v[node][0].left != -1) DFS1(v[node][0].left);
	cout << node << " ";
	if (v[node][0].right != -1) DFS1(v[node][0].right);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num;
		NODE target;
		cin >> num >> target.left >> target.right;
		v[num].push_back(target);
	}
	DFS1(1);
	cout << "\n";
	DFS2(1);
	cout << "\n";
	DFS3(1);
	return 0;
}