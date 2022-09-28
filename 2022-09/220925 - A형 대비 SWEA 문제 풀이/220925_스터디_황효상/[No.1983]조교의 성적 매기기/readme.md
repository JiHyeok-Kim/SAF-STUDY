[문제 사이트] https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PwGK6AcIDFAUq

[문제 설명]

    학기가 끝나고, 학생들의 점수로 학점을 계산중이다.

    학점은 상대평가로 주어지는데, 총 10개의 평점이 있다.
    
![캡처](https://user-images.githubusercontent.com/57944215/192686097-523e4fa5-74e2-43e2-aada-b988161f9580.png)


    학점은 학생들이 응시한 중간/기말고사 점수 결과 및 과제 점수가 반영한다.

    각각 아래 비율로 반영된다.
    
![캡처2](https://user-images.githubusercontent.com/57944215/192686110-f7bdf655-32c8-4938-b48f-02c4b3b1480b.png)


    10 개의 평점을 총점이 높은 순서대로 부여하는데,

    각각의 평점은 같은 비율로 부여할 수 있다.

    예를 들어, N 명의 학생이 있을 경우 N/10 명의 학생들에게 동일한 평점을 부여할 수 있다.

    입력으로 각각의 학생들의 중간, 기말, 과제 점수가 주어지고,

    학점을 알고싶은 K 번째 학생의 번호가 주어졌을 때,

    K 번째 학생의 학점을 출력하는 프로그램을 작성하라.


[제약사항]

    1. N은 항상 10의 배수이며, 10이상 100이하의 정수이다. (10 ≤ N ≤ 100)

    2. K는 1 이상 N 이하의 정수이다. (1 ≤ K ≤ N)

    3. K 번째 학생의 총점과 다른 학생의 총점이 동일한 경우는 입력으로 주어지지 않는다.


[입력]

    입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.

    다음 줄부터 각 테스트 케이스가 주어진다.

    테스트 케이스의 첫 번째 줄은 학생수 N 과, 학점을 알고싶은 학생의 번호 K 가 주어진다.

    테스트 케이스 두 번째 줄 부터 각각의 학생이 받은 시험 및 과제 점수가 주어진다.


[출력]

    테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
    
[입력]

    10
    10 2
    87 59 88
    99 94 78
    94 86 86
    99 100 99
    69 76 70
    76 89 96
    98 95 96
    74 69 60
    98 84 67
    85 84 91
 
[출력]

    #1 A-
 
[풀이 알고리즘]

    학생의 성적을 입력받은 뒤, K번쨰 학생의 학점을 출력하는 문제입니다.

    단순히 학생의 정보를 입력받아 학점을 정렬하여 출력하는 방식을 사용할 경우 K번째 학생이 몇등인지 알 수 없으므로 추가적인 입력을 통해 특정 학생이 K번쨰 학생인지
    
    확인할 수 있도록 해야했습니다.
    
    제가 생각한 풀이 알고리즘은 다음과 같습니다.
    
    1. 학생의 번호와 성적을 저장할 수 있는 구조체를 선언
    
    2. 학생의 정보 입력받기
    
    3. 구조체를 성적에 따라 정렬하는 사용자 정의 함수 구현
    
    4. 구조체 정렬
    
    5. for문을 통해 K번쨰 학생 찾기
    
    6. K번쨰 학생이 상위 몇퍼센트인지 확인 후 학점 출력
    
[구 현]

    #define _CRT_SECURE_NO_DEPRECATE
    #include <iostream>
    #include <vector>
    #include <memory.h>
    #include <algorithm>
    #include <string>

    using namespace std;


    //학생의 번호와 성적을 저장할 구조체 선언
    struct Node {
      int idx;
      int grade;
    };

    //Node 구조체 정렬함수
    bool compare(Node a, Node b) {
      return a.grade > b.grade;
    }
    vector<Node> v;
    int N, K;
    string grade[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
    
    // K번쨰 학생의 성적 출력
    void print(int idx,int t) {
      double one_step = N / 10;

      for (int a = 1; a <= 10; ++a) {
        if (one_step*a >= idx) {
          cout << "#"<<t<<" " <<grade[a - 1] << "\n";
          return;
        }
      }
    }
    void input() {
      int T;
      cin >> T;
      for (int t = 1; t <= T; ++t) {
        v.clear();
        cin >> N >> K;
        
        // 학생의 정보 입력받기
        for (int a = 0; a < N; ++a) {
          int joong, gi, gwa;
          cin >> joong >> gi >> gwa;
          joong = joong *35;
          gi = gi *45;
          gwa = gwa *20;
          v.push_back({ a+1,joong + gi + gwa });
        }
        
        // 구조체 정렬
        sort(v.begin(), v.end(), compare);


        // K번쨰 학생 
        for (int a = 0; a < N; ++a) {
          if (v[a].idx == K) {
            print(a+1,t);
            break;
          }
        }
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
