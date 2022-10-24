문제 사이트 : https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AYLu8mkarlwDFAU-&contestProbId=AWaJ3q8qV-4DFAUQ&probBoxId=AYPvzoJqZD8DFAXj+&type=PROBLEM&problemBoxTitle=20221019&problemBoxCnt=++5+

풀이 환경 : visual studio 2019

언어 : C++

문제 설명 :

    정수론에서, 세 소수 문제란 다음과 같다.

    “5보다 큰 모든 홀수는 정확히 세 소수의 합으로 표현될 수 있다. (같은 소수를 합에 사용해도 된다.)”

    예를 들어, 7 = 2 + 2 + 3, 11 = 2 + 2 + 7, 25 = 7 + 7 + 11로 나타낼 수 있다.

    1939년 러시아 수학자 I. M. Vinogradov는 충분히 큰 홀수는 세 소수의 합으로 표현할 수 있다는 것을 증명했다.

    여기서 충분히 크다는 것은 3315 ≈ 107000000 이상의 수라는 의미이다.

    현재 가장 발전된 하한은 약 e3100 ≈ 101346 이상의 수이다.

    러시아 수학자 I. M. Vinogradov 를 존경하는 새샘이는 직접 세 소수 문제를 풀어보기로 했다.

    하지만 이 수는 너무 크기 때문에 컴퓨터로도 이 범위까지의 모든 수를 증명할 수는 없었다.

    대신 어떤 크지 않은 홀수에 대해, 세 소수의 합으로 나타낼 수 있는 경우의 수를 구하기로 했다.

    5보다 큰 홀수 N을 입력 받아 N = x + y + z (단, x ≤ y ≤ z 이고, x, y, z는 소수) 로 나타나는 경우의 수를 구하는 프로그램을 작성

하라.


[입력]

    첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

    각 테스트 케이스의 첫 번째 줄에 하나의 정수 N ( 7 ≤ N ≤ 999 ) 이 주어진다.

N은 홀수이다.


[출력]

    각 테스트 케이스마다 첫 번째 줄에는 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

    N을 세 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.
 

입력

    3
    7
    11
    25	// test case 개수, T = 3
    // 1st test case, N = 7

 
출력

    #1 1
    #2 2
    #3 5
    

풀이 알고리즘

    5보다 큰 홀수 N 이 주어졌을 때, 세 소수의 합으로 N을 만드는 경우의 수를 출력하는 문제였습니다.

    제가 생각한 문제의 풀이 방법은 다음과 같습니다.

    1. 이 문제를 풀기 위해서는 소수가 필요한데, 각 케이스마다 소수를 구하여 사용하면 시간초과가 

    발생할 수 있으므로, 소수를 미리 구하여 필요에 따라 사용해야하고,

    2. 세가지 숫자를 사용하여 N을 만들어야 하므로, 선택하는 소수는 N 이하여야 하며,

    현재까지 고른 소수의 합 + 새로 고를 소수의 합 <= N 일 경우에만 해당 소수를 골라야합니다.

    3. 세 소수의 합은 순열 케이스 문제이므로, 탐색시 중복된 소수 조합을 고르지 않도록 해야함.

    위의 세가지를 바탕으로 구현을 진행하였고, 큰 문제없이 통과할 수 있었습니다.
    
구 현

    #define _CRT_SECURE_NO_WARNINGS
    #include <iostream>
    #include<vector>
    using namespace std;

    int sosu[1001];
    vector<int> nums;
    int T;
    int N;
    int ans;
    
    // N보다 작은 소수를 빠르게 찾도록 구현한 이진탐색 함수
    int bs(int num) {
        int s = 0;
        int e = nums.size() - 1;
        int target = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] > num) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
                target = mid;
            }
        }

        return target;

    }


    //세개의 소수를 고르는 dfs 함수, 중복된 케이스를 만들지 않기 위해 탐색 시작 위치는 전 탐색에서 탐색햇던 인덱스부터 시작
    void dfs(int deep, int sum,int idx) {
        for (int a = idx; a >= 0; --a) {
            int target = nums[a] + sum;
            if (deep < 2) {
                if (target >= N)
                    continue;
                else
                    dfs(deep + 1, target,a);
            }
            else {
                if (target == N) {
                    ++ans;
                }
            }
        }
    }
    
    // 사용할 소수를 구하는 함수
    void prim() {
        for (register unsigned int a = 2; a <= 1000; ++a) {
            if (sosu[a] == 0) {
                nums.push_back(a);
                for (register unsigned int b = a+a; b <= 1000; b+=a) {
                    if (sosu[b] == 0)
                        sosu[b] = 1;
                }
            }
        }

    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
      //  freopen("Input.txt", "r", stdin);
        prim();
        cin >> T;
        for (int t = 1; t <= T; ++t) {
            cin >> N;
            int size = nums.size() - 1;
            int start = bs(N);
            for (int a = start; a >= 0; --a) {
                dfs(1, nums[a],a);
            }
            cout << "#"<<t<<" " <<ans << "\n";
            ans = 0;
        }
        return 0;
    }
