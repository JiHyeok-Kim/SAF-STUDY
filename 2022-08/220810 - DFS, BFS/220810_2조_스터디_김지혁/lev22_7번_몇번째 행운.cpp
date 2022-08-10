] = { 'A','B','C','D' };
int cnt = 0;
string str;

void run(int lev)
{
	if (lev == 3)
	{
		cnt++;
		int flag = 0;
		for (int i = 0; i < 3; i++) {
			flag = 0;
			if (path[i] != str[i]) break;
			flag = 1;
		}
		if (flag == 1) { cout << cnt << "번째"; }
		return;
	}

	for (int i = 0; i < 4; i++) {

		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
	}

	return;
}

int main()
{
	cin >> str;
	run(0);
}