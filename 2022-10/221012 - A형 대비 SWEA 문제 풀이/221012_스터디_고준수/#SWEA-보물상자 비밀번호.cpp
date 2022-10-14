#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*문제 풀이

*/
string sep_word[28][4];
int arr[28][4];
int N;



vector<int> alist;
int string_to_hex(string s)
{
	int sum_num = 0;
	for (int i = 0; i < N / 4; i++)
	{
		if (s[s.size() - 1 - i] == '1')
		{
			sum_num += pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '2')
		{
			sum_num += 2 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '3')
		{
			sum_num += 3 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '4')
		{
			sum_num += 4 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '5')
		{
			sum_num += 5 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '6')
		{
			sum_num += 6 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '7')
		{
			sum_num += 7 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '8')
		{
			sum_num += 8 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == '9')
		{
			sum_num += 9 * pow(16, i);

		}
		else if (s[s.size() - 1 - i] == 'A')
		{
			sum_num += 10 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == 'B')
		{
			sum_num += 11 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == 'C')
		{
			sum_num += 12 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == 'D')
		{
			sum_num += 13 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == 'E')
		{
			sum_num += 14 * pow(16, i);
		}
		else if (s[s.size() - 1 - i] == 'F')
		{
			sum_num += 15 * pow(16, i);
		}
	}
	return sum_num;
}


int main()
{
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{

		cin >> N;
		int K;
		cin >> K;

		string word;
		cin >> word;
		string new_word = word;
		int cnt = 0;
		int turn_cnt = 1;
		for (int j = 0; j < N / 4; j++)
		{


			while (cnt < 4)
			{
				for (int i = 0; i < N / 4; i++)
				{
					sep_word[j][cnt] += new_word[i];
				}
				new_word = new_word.substr(N / 4);
				cnt++;
			}
			if (turn_cnt == N / 4) break;

			string last_word = word.substr(word.size() - turn_cnt);
			new_word = word.substr(0, word.size() - turn_cnt);
			last_word += new_word;
			new_word = last_word;


			cnt = 0;
			turn_cnt++;
		}



		for (int i = 0; i < N / 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[i][j] = string_to_hex(sep_word[i][j]);
				alist.push_back(arr[i][j]);
			}
		}

		sort(alist.begin(), alist.end(), greater<int>());
		alist.erase(unique(alist.begin(), alist.end()), alist.end());
		cout << '#' << tc + 1 << ' ' << alist[K - 1] << '\n';
		int de = 0;

		alist.clear();


	}





	return 0;
}