#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int n;
    char ch;
};

bool compare(Node t, Node v) {
    //t가 v보다 우선순위 높으면 1
    //그렇지 않으면 0 리턴


    //1번 조건 문자 작은것
    if (t.n < v.n) return 1;
    if (t.n > v.n) return 0;

    //if (t.n > v.n) return 1;
    //return 0;

    return t.ch < v.ch;
}

int main() {

    vector<Node> arr;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        arr.push_back({ a , b });
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].n << " " << arr[i].ch << '\n';

    }

    return 0;
}