문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWgv9va6HnkDFAW0

문제 설명 :

    규영이와 인영이는 1에서 18까지의 수가 적힌 18장의 카드로 게임을 하고 있다.

    한 번의 게임에 둘은 카드를 잘 섞어 9장씩 카드를 나눈다. 
    
    그리고 아홉 라운드에 걸쳐 게임을 진행한다.

    한 라운드에는 한 장씩 카드를 낸 다음 두 사람이 낸 카드에 적힌 수를 비교해서 점수를 계산한다.

    높은 수가 적힌 카드를 낸 사람은 두 카드에 적힌 수의 합만큼 점수를 얻고,

    낮은 수가 적힌 카드를 낸 사람은 아무런 점수도 얻을 수 없다.

    이렇게 아홉 라운드를 끝내고 총점을 따졌을 때, 총점이 더 높은 사람이 이 게임의 승자가 된다.

    두 사람의 총점이 같으면 무승부이다.

    이번 게임에 규영이가 받은 9장의 카드에 적힌 수가 주어진다.

    규영이가 내는 카드의 순서를 고정하면, 인영이가 어떻게 카드를 내는지에 따른 9!가지 순서에 따라

    규영이의 승패가 정해질 것이다.

    이 때, 규영이가 이기는 경우와 지는 경우가 총 몇 가지 인지 구하는 프로그램을 작성하라.


[입력]

    첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

    각 테스트 케이스의 첫 번째 줄에는 아홉 개의 정수가 공백으로 구분되어 주어진다.

    각 정수는 1이상 18이하이며, 같은 정수는 없다.

    규영이는 정수가 주어지는 순서대로 카드를 낸다고 생각하면 된다.


[출력]

    각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고 한 칸을 띄운 후,

    인영이가 카드를 내는 9! 가지의 경우에 대해 규영이가 게임을 이기는 경우의 수와 게임을 지는 경우의 수를

    공백 하나로 구분하여 출력한다.

[예시 입력]

4  //테스트 케이스 개수
1 3 5 7 9 11 13 15 17 //1st TC, 9장의 카드에 대한 정보  
18 16 14 12 10 8 6 4 2 //2nd TC
13 17 9 5 18 7 11 1 15
1 6 7 9 12 13 15 17 18	

[예시 출력]

#1 112097 250783//첫 번째 테스트케이스 결과
#2 250783 112097//두 번째 테스트케이스 결과
#3 336560 26320
#4 346656 16224	

[풀이 알고리즘]

  규영이와 인영이가 1~18까지 값이 적혀있는 18장의 카드를 가지고 게임을 하고, 규영이가 낼 카드의 정보가 주어질 때, 규영이가 
  
  이기는 횟수와 지는 횟수를 출력하는 문제입니다.
  
  제가 생각한 이 문제의 풀이 방법은 다음과 같습니다.
  
  [ 필요한 정보 ]
  1. 인영이의 카드정보 
    - 규영이의 카드정보가 주어져 있기 때문에 규영이가 가지고 있는 카드를 제외한 카드를 인영이의 카드정보로 입력
  
  2. 게임이 진행되었다면 인영이가 현재까지 낸 카드의 정보
    - 규영이가 내는 카드의 순서는 정해져있으므로 인영이가 낼 카드의 정보가 필요한데, 인영이가 기존에 냈었던 카드는
      내지않도록 해야하기 때문에 인영이가 현재단계에서 특정 카드를 사용햇다면 해당 카드를 사용했음을 표시하여 재사용 방지
  
  3. 게임 진행 중 인영이와 규영이의 점수
    - 게임이 끝나면 서로의 점수를 비교하여 규영이의 승리,패배 횟수를 카운팅해야하므로 점수를 기록하여 마지막에 비교할 수 있도록 
      구현.
  
  [알고리즘]
  
  1. 규영이의 카드정보를 바탕으로 인영이의 카드정보 세팅
  
  2. 세팅된 정보를 바탕으로 9번의 게임을 dfs로 진행.
  
  3. 진행과정에서 모든 경우의 수를 가정해야하므로 현재단계에서 인영이가 가진 9개의 카드 중 사용하지 않은 카드를 모두 사용하도록
     하여 총 9!의 경우의수를 탐색
  
  4. 카드를 9개 사용했다면 서로의 점수를 비교하여, 규영이의 점수가 클경우 승리횟수, 작은 경우 패배횟수를 증가

  5. 모든 경우의 수를 탐색했다면 해당 횟수 출력


[구 현]

    #define _CRT_SECURE_NO_DEPRECATE
    #include <iostream>
    #include <vector>
    #include <memory.h>
    #include <algorithm>
    #include <string>

    using namespace std;



    int total_card_set[19];
    int your_set[9];
    int my_set[9];

    int win_cnt = 0;
    int lose_cnt = 0;
    bool used[9];

    void dfs(int deep, int gyu, int inyung) {
    
    // 카드를 9개 냈다면 점수비교
      if (deep == 9) {
        if (gyu > inyung)
          ++win_cnt;
        else if (gyu < inyung)
          ++lose_cnt;
        return;
      }

      //현재까지 냈던 카드 중 내지 않은 카드를 골라 규영이의 카드와 비교 후 점수추가 및 카드게임 진행
      for (int a = 0; a < 9; ++a) {
        if (used[a] == 0) {
          used[a] = 1;
          if (my_set[a] > your_set[deep]) {
            dfs(deep + 1, gyu, my_set[a] + your_set[deep] + inyung);
          }
          else {
            dfs(deep + 1, gyu + my_set[a] + your_set[deep], inyung);
          }
          used[a] = 0;
        }
      }
    }
    void input() {
      int T;
      cin >> T;
      for (int t = 1; t <= T; ++t) {
        memset(total_card_set, 0, sizeof(total_card_set));
        memset(your_set, 0, sizeof(your_set));
        memset(my_set, 0, sizeof(my_set));
        win_cnt = 0;
        lose_cnt = 0;

        // 규영이가 사용한 카드정보 입력
        for (int a = 0; a < 9; ++a) {
          cin >> your_set[a];
          total_card_set[your_set[a]] = 1;
        }
        int idx = 0;
        
        // 내가 사용할 카드정보 입력
        for (int a = 1; a <= 18; ++a) {
          if (total_card_set[a] == 0)
            my_set[idx++] = a;
        }

        //카드게임 시작
        dfs(0, 0, 0);
        cout << "#"<<t << " " <<win_cnt << " " << lose_cnt << "\n";
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
