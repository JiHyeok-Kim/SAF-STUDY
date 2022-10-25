문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw

문제 설명 :

    준환이는 N개의 서로 다른 무게를 가진 무게 추와 양팔저울을 가지고 있다.

    모든 무게 추를 양팔저울 위에 올리는 순서는 총 N!가지가 있고,

    여기에 더해서 각 추를 양팔저울의 왼쪽에 올릴 것인지 오른쪽에 올릴 것인지를 
    
    정해야 해서 총 2N * N!가지의 경우가 있다.

    하지만 양팔 저울에 갑자기 문제가 생겨서 무게 추를 올릴 때 오른쪽 위에 올라가 있는
    
    무게의 총합이 왼쪽에 올라가 있는 무게의 총합보다 더 커져서는 안 된다.

    예를 들어 무게추가 총 3개, 무게가 각각 1, 2, 4 라고 하면 아래 그림처럼 총 15가지 경우가 나올 수 있다.

![download](https://user-images.githubusercontent.com/57944215/197754528-349f7e66-b371-4b97-b801-149f9b9fc80f.png)


    이런 방법으로 준환이가 양팔 저울에 모든 무게추를 올리는 방법은 총 몇 가지가 있을까?


[입력]

    첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

    각 테스트 케이스마다 첫 번째 줄에 N(1 ≤ N ≤ 9)가 주어진다.

    두 번째 줄에는 각 무게추의 무게를 의미하는 N개의 자연수가 공백으로 구분되어 주어진다. 
    
    무게는 1이상 999이하이다.


[출력]

    각 테스트 케이스마다 무게추를 올리는 과정에서 오른쪽 위에 올라가있는 무게의 
    
    총합이 왼쪽에 올라가 있는 무게의 총합보다 커지지 않는 경우의 수를 출력한다.

 

입력

    3
    3
    1 2 4
    3
    1 2 3
    9
    1 2 3 5 6 4 7 8 9	//testCase의 개수
    
출력

    #1 15
    #2 17
    #3 35583723
    
풀이 알고리즘

    N개의 무게추가 주어질 때, 주어진 조건에 맞추어 가능한 경우의 수를 출력하는 문제였습니다.
    
    단순히 경우의 수를 찾아 계산할 경우 문제에 주어진대로 2N * N! 개의 경우가 생기므로 시간초과가 발생할 수 있는 문제입니다.
    
    그래서 문제의 풀이 과정에서 시간초과가 발생하지 않도록 연산의 수를 줄여주는 과정이 필요했는데 제가 생각한 그 과정은 
    
    현재 left에 있는 무게추의 총 합이, 총 무게의 50%이상을 차지할 때 입니다.
    
    left에 있는 무게추의 총 합이 50%이상일 경우 어떤 방법으로 무게추를 놓아도 left보다 right가 커질 수 잇는 경우의 수가 없으므로 
    
    left가 right보다 항상 큰 경우가 되고, 해당 경우의 수 들을 수학적으로 처리하여 연산 횟수를 줄이면 시간초과를 벗어날 수 있다고 생각했습니다,
    
    그래서 left가 right보다 커지는 상황에서 남은 무게추의 갯수 가 X라고 했을 때, 한줄로 무게추를 나열할 경우 X!만큼의 경우의 수가 생기고.
    
    left와 right로 나눌경우 무게추가 하나 증가할 때마다 놓을 수 있는 방법이 2개씩 증가하므로 2^X * X! 를 경우의 수에 더해주면 현재 상황에서
    
    가능한 모든 경우의 수가 정답에 더해지게 됩니다.
    
구 현

    #define _CRT_SECURE_NO_WARNINGS
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    using namespace std;

    int T, N;
    double nums[10];
    bool used[10];
    double mid = 0;
    int ans = 0;

    int fac(int num) {
        int start = 2;
        int idx = 2;
        while (idx <= num) {
            start = start * idx*2;
            ++idx;
        }
        return start;
    }
    void dfs(double left, double right, int deep) {
        if (deep == N) {
            ++ans;
            return;
        }

        if (left >= mid) {
            ans = ans + fac(N - deep);
            return;
        }
        for (int a = 0; a < N; ++a) {
            if (used[a] == 0) {
                double duhagi = right + nums[a];
                used[a] = 1;
                if ((left >= duhagi) && duhagi <= mid) {
                    dfs(left, duhagi, deep + 1);
                }
                dfs(left + nums[a], right, deep + 1);
                used[a] = 0;
            }
        }
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
      //  freopen("Input.txt", "r", stdin);
        cin >> T;
        for (int t = 1; t <= T; ++t) {
            cin >> N;
            ans = 0;
            double tmp = 0;
            for (int a = 0; a < N; ++a) {
                cin >> nums[a];
                tmp += nums[a];
            }
            mid = tmp / 2;
            for (int a = 0; a < N; ++a) {
                used[a] = 1;
                dfs(nums[a], 0, 1);
                used[a] = 0;
            }
            cout << "#" << t << " " << ans << "\n";
        }


        return 0;
    }
