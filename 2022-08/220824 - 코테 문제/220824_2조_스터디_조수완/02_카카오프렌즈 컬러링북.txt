#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int maxi = -1;
    struct Node{
        int y,x;
    };
    queue<Node> q;
    
    for(int y = 0; y < m ; y++){
        for(int x = 0 ; x < n ; x++){
            if(picture[y][x] == 0) continue;
            int cnt = 1;
            int tar = picture[y][x];
            q.push({y,x});
            picture[y][x]=0;
            
            while(!q.empty()){
                Node now = q.front();
                q.pop();
                
                int drY[4]={-1,1,0,0};
                int drX[4]={0,0,-1,1};
                for(int i=0;i<4;i++){
                    int ny = now.y + drY[i];
                    int nx = now.x + drX[i];
                    if(ny<0||nx<0||ny>=m||nx>=n) continue;
                    if(picture[ny][nx] != tar) continue;
                    picture[ny][nx] = 0;
                    q.push({ny,nx});
                    cnt++;
                }
            }
            number_of_area++;
            maxi = max(maxi,cnt);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = maxi;
    return answer;
}