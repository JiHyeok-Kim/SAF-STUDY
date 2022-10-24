문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWRuoqCKkE0DFAXt


풀이 환경 : Visual Studio 2019


문제 설명 :

    테네스는 소수를 좋아한다. 
    
    소수란 1과 자기 자신만으로 나뉘어 떨어지는 숫자로 작은 것부터 나열하면 
    
    2, 3, 5, 7, 11, 13, 17, 19, 23, …같은 수들이 있다.

    또한 테네스는 D를 포함하는 숫자도 좋아한다. 
    
    그렇기에 소수가 D를 포함하면 더욱 더 좋아하여 특별한 소수라고 부르기로 했다.

    예를 들어 D = 3이면 3, 13, 23, … 같은 소수들이 3을 포함하였으므로
    
    테네스는 이런 숫자들을 특별한 소수라고 부를 것이다.

    D가 주어질 때, A이상 B이하의 수 중에서 특별한 소수인 것들의 개수를 구하는 프로그램을 작성하라.


[입력]

    첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

    각 테스트 케이스의 첫 번째 줄에는 세 정수 D, A, B(1 ≤ D ≤ 9, 1 ≤ A ≤ B ≤ 106)가 
    
    공백으로 구분되어 주어진다.

[출력]

    각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 특별한 소수의 개수를 출력한다.

입력

    2
    3 10 30
    7 1 1000000	//Test Case 수
    //Test Case 1의 D, A, B
 
출력

    #1 2
    #2 43506
    
    
풀이 알고리즘 

    포함되어야 하는 숫자 D와 최소값 A, 최대값 B가 주어졌을 때, A <= X <= B 를 만족하며
    
    D가 포함된 소수 X의 갯수를 찾는 문제였습니다.
    
    이 문제에서 찾는 X의 조건은 1) 소수 2) D가 포함된 수 입니다.
    
    위의 조건을 보며 제가 생각한 풀이 알고리즘은 다음과 같습니다.
    
    1. 소수를 미리 구해놓기
    
    2. A <= X <= B를 만족하는 X 중 D 가 포함되었는지 확인하기
    
    1.의 경우는 미리 소수를 구하면 되지만
    
    2.는 숫자에 포함된 D를 찾기 위해서 나누기 연산을 할 경우 시간초과가 발생하므로
    
    string값으로 변환하여 한칸씩 탐색하며 D가 존재하는지 확인하는 방법으로 구현했습니다.
    
    
구 현

    #define _CRT_SECURE_NO_WARNINGS
    #include <iostream>
    #include<vector>
    #include <algorithm>
    #include <string>
    using namespace std;

    int sosu[1000001];
    vector<int> nums;
    int T;
    char D;
    int A, B;
    
    
    // A 큰 수 중 가장 작은 수 찾기
    int bs1(int num) {
        int s = 0;
        int e = nums.size() - 1;
        int target = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] >= num) {
                target = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return target;

    }
    
    // B보다 작은 수 중 가장 큰 수 찾기
    int bs2(int num) {
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
    
    // 100만 이하의 소수 찾기
    void prim() {
        for (register unsigned int a = 2; a <= 1000000; ++a) {
            if (sosu[a] == 0) {
                nums.push_back(a);
                for (register unsigned int b = a+a; b <= 1000000; b+=a) {
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
       // freopen("Input.txt", "r", stdin);
        prim();
        cin >> T;
        for (int t = 1; t <= T; ++t) {
            cin >> D >> A >> B;
            int start = bs1(A);
            int end = bs2(B);
            int ans = 0;
           for (int a = start; a <= end; ++a) {

                // 가장 작은 소수가 B보다 클 경우, 즉 A <= X <= B를 만족하는 X가 없을 경우
                if (nums[a] > B)
                    break;
                    
                    // 찾은 소수를 string 값으로 변환 뒤
                string tmp = to_string(nums[a]);
                
                // string안에 D가 존재하는지 확인
                for (int b = 0; b < tmp.length(); ++b) {
                    if (tmp[b] == D) {
                        ++ans;
                        break;
                    }
                }

            }
            cout << "#"<<t<<" "<<ans << "\n";
        }
        return 0;
    }
    
