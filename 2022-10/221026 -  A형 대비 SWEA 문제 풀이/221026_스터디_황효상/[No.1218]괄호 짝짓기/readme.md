문제 사이트 : https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AYLu8mkarlwDFAU-&contestProbId=AV14eWb6AAkCFAYD&probBoxId=AYQT9CfauO0DFAXj&type=PROBLEM&problemBoxTitle=20221026&problemBoxCnt=5#none

문제 설명 :

    4 종류의 괄호문자들 '()', '[]', '{}', '<>' 로 이루어진 문자열이 주어진다.

    이 문자열에 사용된 괄호들의 짝이 모두 맞는지 판별하는 프로그램을 작성한다.

    예를 들어 아래와 같은 문자열은 유효하다고 판단할 수 있다.

![SW문제해결+기본 +4일차+-+괄호+짝짓기_그림1](https://user-images.githubusercontent.com/57944215/199258180-5249f511-dde5-4b65-b12e-892ca006ff82.png)


    아래와 같은 문자열은 유효하지 않은 문자열이다. 붉은색으로 표시된 괄호의 짝을 찾을 수 없기 때문이다.

![SW문제해결+기본 +4일차+-+괄호+짝짓기_그림2](https://user-images.githubusercontent.com/57944215/199258184-615676af-596e-4eeb-8f5f-06834c0d338b.png)


    아래 문자열은 열고 닫는 괄호의 개수는 유효하나 짝이 맞지 않는 괄호가 사용 되었기 때문에 유효하지 않다.

![SW문제해결+기본 +4일차+-+괄호+짝짓기_그림3](https://user-images.githubusercontent.com/57944215/199258193-ae709548-1b0c-4b38-97d2-9ebf129d32c6.png)


[입력]

    각 테스트 케이스의 첫 번째 줄에는 테스트케이스의 길이가 주어지며, 
    
    다음 줄에 테스트 케이스가 주어진다.

    총 10개의 테스트케이스가 주어진다.

[출력]

    #부호와 함께 테스트 케이스의 번호를 출력하고, 
    
    공백 문자 후 유효성 여부를 1 또는 0으로 표시한다 (1 - 유효함, 0 - 유효하지 않음).

입력

    182
    (({<(({{[[[[<<[[(<[[{([{{{[<[[[{<<(<[[{}[]{}{}[]]]><><...
    298
    {(({[({([{(<[([(([<({[{{[[({{[({([<{(<[[((<{{[([{<<[{(<({[<(...

출력

  #1 1
  #2 0


풀이 알고리즘

    문자열 입력값으로 주어질 때, 해당 문자열에 존재하는 괄호쌍이 모두 유효한지 확인하는 문제였습니다.
    
    해당 문제에서 허용하는 유효한 괄호쌍은 다음과 같습니다.
    
    1. 여는 괄호 : { [ ( <
    2. 닫는 괄호 : } ] ) >
    
    해당 괄호쌍을 바탕으로 유효한 괄호쌍을 판단하는 방법은 다음과 같습니다.
    
    1. 여는 괄호를 만났을 경우 stack에 push한다.
    
    2. 닫는 괄호를 만났을 경우 stack의 최상단에 존재하는 괄호가 현재 만난 닫는 괄호와 
    
    유효한 여는 괄호일경우 stack 최상단 값을 pop하고 다음 탐색을 진행한다.
    
    위의 유효성 확힌을 
    
    입력값의 길이가 L일경우 0번 index부터 L-1 index까지 탐색하며 모두 유효한 괄호쌍인지 확인하여
    
    문제를 해결하였습니다.
    

구 현

    #define _CRT_SECURE_NO_WARNINGS
    #include<iostream>
    #include <string>
    #include <stack>

    using namespace std;


    stack<char> st;
    string input;
    int leng;
    void init() {
      while (st.size() > 0) {
        st.pop();
      }
    }
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
    //	freopen("input.txt", "r", stdin);


      for (int t = 1; t <= 10; ++t) {
        cin >> leng >> input;
        init();
        int flag = 1;
        for (int a = 0; a < input.length(); ++a) {
          if (input[a] == '(' || input[a] == '{' || input[a] == '<' || input[a] == '[') {
            st.push(input[a]);
          }
          else {
            char target = st.top();
            st.pop();
            if (input[a] == ')') {
              if (target != '(') {
                flag = 0;
                break;
              }
            }
            else if (input[a] == '}') {
              if (target != '{') {
                flag = 0;
                break;
              }

            }
            else if (input[a] == '>') {
              if (target != '<') {
                flag = 0;
                break;
              }
            }
            else {
              if (target != '[') {
                flag = 0;
                break;
              }
            }
          }
        }
        if (flag && st.size() == 0) {
          cout << "#" << t << " 1\n";
        }
        else {
          cout << "#" << t << " 0\n";
        }
      }
    }
