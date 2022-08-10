#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int left;
	int right;
};

vector<Node> tree(1000);

int n;

vector<int> path;

void dfs(int now) {

	if (tree[now].left != -1) dfs(tree[now].left);
	if (tree[now].right != -1) dfs(tree[now].right);

	cout << now << " ";
}

void dfs2(int now) {
	cout << now << " ";

	if (tree[now].left != -1) dfs2(tree[now].left);
	if (tree[now].right != -1) dfs2(tree[now].right);
}

void dfs3(int now) {

	if (tree[now].left != -1 && tree[now].left) dfs3(tree[now].left);

	cout << now << " ";

	if (tree[now].right != -1 && tree[now].right) dfs3(tree[now].right);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx, l, r;
		cin >> idx >> l >> r;
		tree[idx].left = l;
		tree[idx].right = r;
	}
	dfs3(1);
	cout << '\n';
	dfs2(1);
	cout << '\n';
	dfs(1);

	return 0;
}