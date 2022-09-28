[문제 사이트] https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq

[문제 설명]

    N X N 크기의 단어 퍼즐을 만들려고 한다.
    
    입력으로 단어 퍼즐의 모양이 주어진다.

    주어진 퍼즐 모양에서 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수를 출력하는 프로그램을 작성하라.

    
    N = 5, K = 3 이고, 퍼즐의 모양이 아래 그림과 같이 주어졌을 때


![캡처](https://user-images.githubusercontent.com/57944215/192670695-61d9d8f4-8428-4f49-9cbc-2734c92ca03a.png)


    길이가 3 인 단어가 들어갈 수 있는 자리는 2 곳(가로 1번, 가로 4번)이 된다.
    
![캡처2](https://user-images.githubusercontent.com/57944215/192670711-c31451a1-48ed-4492-839a-2781a897e471.png)


[제약 사항]

    1. N은 5 이상 15 이하의 정수이다. (5 ≤ N ≤ 15)

    2. K는 2 이상 N 이하의 정수이다. (2 ≤ K ≤ N)


[입력]

    입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.

    다음 줄부터 각 테스트 케이스가 주어진다.

    테스트 케이스의 첫 번째 줄에는 단어 퍼즐의 가로, 세로 길이 N 과, 단어의 길이 K 가 주어진다.

    테스트 케이스의 두 번째 줄부터 퍼즐의 모양이 2차원 정보로 주어진다.

    퍼즐의 각 셀 중, 흰색 부분은 1, 검은색 부분은 0 으로 주어진다.


[출력]

    테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

[입력]

    10
    5 3
    0 0 1 1 1
    1 1 1 1 0
    0 0 1 0 0
    0 1 1 1 1
    1 1 1 0 1
    5 3
    1 0 0 1 0
    1 1 0 1 1
    1 0 1 1 1
    0 1 1 0 1
    0 1 1 1 0
 
[출력]

    #1 2
    #2 6

[풀이 알고리즘]

    주어진 퍼즐 칸안에 K길이의 단어를 넣을 수 있는 갯수를 구하는 문제였습니다.
    
    주어진 퍼즐의 빈 칸이 정확히 K만큼이라면 K단어를 넣을 수 있고, K보다 크면 넣을 수 없는것이 조건이기 때문에
    
    해당 사항을 정확히 인지하고 풀어야하는 문제였습니다.
    
    이 문제의 풀이 알고리즘은 다음과 같습니다
    
    1. N개의 행에 대하여 가로탐색을 진행하고, 다음과 같은 연산을 진행합니다.
      1) 빈칸이라면 현재까지 연속된 빈칸 +1
      2) 빈칸이 안니라면 현재까지 연속된 빈칸의 갯수를 확인하고 K와 같다면 정답+1, 아니면 연속된 빈칸을 0으로 초기화
      3) 한 행의 탐색이 끝낫을 때, 연속된 빈칸의 갯수가 K개라면 정답 +1
    
    2. N개의 열에 대하여 가로탐색을 진행하고, 다음과 같은 연산을 진행합니다.
      1) 빈칸이라면 현재까지 연속된 빈칸 +1
      2) 빈칸이 안니라면 현재까지 연속된 빈칸의 갯수를 확인하고 K와 같다면 정답+1, 아니면 연속된 빈칸을 0으로 초기화
      3) 한 열의 탐색이 끝낫을 때, 연속된 빈칸의 갯수가 K개라면 정답 +1
      
    필요한 칸의 갯수가 정확히 K개라는 사실과, 정답의 갯수를 더해주는 조건이 
      1) 벽을 만났을 때, 연속된 빈칸의 갯수가 K개
      2) 한 구역의 탐색이 끝나고 연속된 빈칸의 갯수가 K개
      
      두가지 케이스인것만 확인하면 쉬운 문제였습니다.



[구현]

    #define _CRT_SECURE_NO_DEPRECATE
    #include <iostream>
    #include <vector>
    #include <memory.h>

    using namespace std;


    int map[15][15];
    int N, M;

    // 행탐색
    int row_cnt() {
      int ans = 0;
      for (int a = 0; a < N; ++a) {
        int cnt = 0;
        for (int b = 0; b < N; ++b) {
        
          // 현재칸이 빈칸이라면 연속된 빈칸갯수 +1
          if (map[a][b] == 1)
            ++cnt;
          else {
          
          //현재칸이 빈칸이 아니고 전칸까지는 빈칸이였다면
            if (cnt > 0) {
            
            // 전칸까지 빈칸의 갯수를 확인하고 문제에서 주어진 M값과 같다면 정답 +1
              if (cnt == M
                ++ans;
                
                //아니라면 빈칸 갯수만 0으로 초기화
              cnt = 0;
            }
          }
        }
        // 한 행의 탐색 종료 후 종료전까지 연속된 빈칸의 갯수가 M개였다면 정답 +1
        if (cnt == M)
          ++ans;
      }

      return ans;

    }


    // 행탐색과 동일한 동작
    int col_cnt() {
      int ans = 0;
      for (int a = 0; a < N; ++a) {
        int cnt = 0;
        for (int b = 0; b < N; ++b) {
          if (map[b][a] == 1)
            ++cnt;
          else {
            if (cnt > 0) {
              if (cnt == M)
                ++ans;
              cnt = 0;
            }
          }
        }
        if (cnt == M)
          ++ans;
      }

      return ans;

    }
    void input() {
      int T;
      cin >> T;
      for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        memset(map, 0, sizeof(map));
        
        // 
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < N; ++b) {
            cin >> map[a][b];
          }
        }
        cout << "#" << t << " " << row_cnt() + col_cnt()<<"\n";
      }
    }
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      //freopen("input.txt", "r", stdin);
      input();

      return 0;
    }
