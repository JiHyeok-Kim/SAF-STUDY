#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

float sum_score = 0;
float dul_score[100];
float score[100];
typedef struct {
	int idx;
	float score;
	
}Node;

void init(int n)
{
	sum_score = 0;
	for (int i = 0; i < 100; i++)
	{
		score[i] = 0;
		dul_score[i] = 0;
		
	}
}





vector<Node> new_score;

string grade[10] = { "A+", "A0", "A-", "B+", "B0", "B-","C+", "C0", "C-","D0" };

int tc_cnt = 1;
int main()
{
	int tc;
	cin >> tc;


	for (int testcase = 0; testcase < tc; testcase++)
	{
		
		new_score.clear();
		int flag = 0;
		int people;
		cin >> people;
		int target;
		cin >> target;
		init(people);


		
		for (int i = 0; i < people; i++)
		{
			float mid_score;
			float last_score;
			float homework_score;

			cin >> mid_score;
			cin >> last_score;
			cin >> homework_score;

			sum_score = (mid_score * 0.35) + (last_score * 0.45) + (homework_score * 0.2);
			score[i] = sum_score;
			dul_score[i] = sum_score;

			

		}

		int de = 0;
		sort(score, score + people, greater<>());

		for (int i = 0; i < people; i++)
		{
			new_score.push_back({ i,score[i] });
		}

		for (int i = 0; i < people; i++)
		{
			if (new_score[i].score == dul_score[target-1])
			{
				cout << "#" << tc_cnt << ' ' << grade[i/(people/10)] << '\n';
				tc_cnt++;
				flag++;
				break;
			}
		}
		





	}
	return 0;
}
