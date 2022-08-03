#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {

    string ch;
    int n;
    int index;
};

bool compare(Node t, Node v) {
    //t가 v보다 우선순위 높으면 1
    //그렇지 않으면 0 리턴


    //1번 조건 문자 작은것
    if (t.n > v.n) return 1;
    if (t.n < v.n) return 0;

    if (t.index > v.index) return 1;
    if (t.index < v.index) return 0;



    return t.index < v.index;
}

int main() {

    vector<Node> arr;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        arr.push_back({ a , b ,i });
        sort(arr.begin(), arr.end(), compare);
        for (int j = 0; j < arr.size(); j++)
        {
            if (j == 3) break;
            cout << arr[j].ch << ' ';

        }
        cout << '\n';
    }




    return 0;
}