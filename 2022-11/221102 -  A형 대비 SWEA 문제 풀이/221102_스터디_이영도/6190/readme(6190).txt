정곤이의 단조 증가하는 수 


방법[1] 실패 (문제 이해 잘못함)
0 test case & N 입력 받
1 vector<string> 로 각 각의 숫자들 입력 받
2 isValid 함수 맹글어서 
3 for문으로 각 각의 숫자들 for문으로 돌면서 isValid 함수로 보냄 
4 isValid 함수에서 한 글자씩 때어가며 단조 증가하는 수가 맞다면 
5 배열이든 vector든 하나씩 넣어
6 그거 sort 시키고 제일 큰 거 두개 골라서 곱하기 하고 출력하면 
끝


방법[2] 
0 test case & N 입력 받
1 배열로 각각의 숫자 입력 받기
2 DFS 함수와 isValid 함수 맹글고
3 DFS로 각각의 숫자 조합
4 DFS에서 if(종료조건 == 2) {
	두 수 곱하기 
	곱해진 값 isValid 함수로 보내고	
5 isValid 함수에서 단조 증가하는 수 인지 확인하고 DFS로 
	되돌아와서 단조 증가하는 수가 맞으면 MAX 값이랑 비교해서 
	갱신 or 넘어가고 아니면 그냥 넘어가고
6 main에서 MAX 값 출력하면 끝



[input]
1 		testcase
4 		N
2 4 7 10 	숫자들

[output]
#1 28		10은 단조 증가하는 수가 아니고 2 4 7 중에 4 x 7이
		최댓값이니까 4 x 7 = 28 해서 답이 28인거임
없다면 -1 출력




* DFS 돌 때
[순열] 경우
DFS(cnt)
if(cnt == 종료조건)
for(0 ~ N) 돌면 되고
[조합] 경우엔
DFS(cnt, StartPoint)
if(cnt == 종료조건)
for(StartPoint ~ N) 돌면 더욱 효과적임








