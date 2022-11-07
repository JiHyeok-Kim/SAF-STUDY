#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;
int N, M;
int answer;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> N >> M;
        answer = 0;
        um.clear();
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            um[str] = 1;
        }
        for (int i = 0; i < M; i++) {
            string str;
            cin >> str;
            if (um.count(str) == 1) answer++;
        }

        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}