#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct tri {
    int x;
    int y;
    int z;
};

bool operator<(tri A, tri B) {
    return false;
}

int N, M;
int answer = 0;
vector<int> graph[51];
set<tri> st;

void init() {
    cin >> N >> M;
    answer = 0;
    st.clear();
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

void searchTri(int lev, int arr[3]) {
    if (lev == 3) {
        int flag = 1;
        for (int loop : graph[arr[2]]) {
            if (loop == arr[0]) flag = 0;
        }
        if (flag) return;
        answer++;
        return;
    }

    for (int loop : graph[arr[lev - 1]]) {
        if (lev == 1 && loop <= arr[0]) continue;
        if (lev == 2 && loop <= arr[1]) continue;
        arr[lev] = loop;
        searchTri(lev + 1, arr);
        arr[lev] = 0;
    }

}

void solve() {
    for (int i = 1; i <= N; i++) {
        int arr[3] = { i,0,0, };
        searchTri(1, arr);
    }
}

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();

        solve();

        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}