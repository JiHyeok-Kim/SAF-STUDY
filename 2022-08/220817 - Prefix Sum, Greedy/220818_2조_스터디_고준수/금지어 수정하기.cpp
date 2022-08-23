#include <iostream>
#include <string>

using namespace std;

int main()
{
	string bbq;
	cin >> bbq;
	//KFC 라는 단어를 MC 로 변경 KFC는 단 ㅎ나만 존재;
	int a = 0;
	while (1) {


		int idx1 = bbq.find("KFC", a);
		if (idx1 == -1)break;
		a++;
		bbq.erase(idx1, 3);
		bbq.insert(idx1, "#BBQ#");
	}

	while (1) {


		int idx2 = bbq.find("MC", a);
		if (idx2 == -1)break;
		a++;
		bbq.erase(idx2, 2);
		bbq.insert(idx2, "#BBQ#");
	}

	while (1) {


		int idx3 = bbq.find("BICMAC", a);
		if (idx3 == -1)break;
		a++;
		bbq.erase(idx3, 6);
		bbq.insert(idx3, "#MACBOOK#");
	}



	while (1) {


		int idx4 = bbq.find("SHACK", a);
		if (idx4 == -1)break;
		a++;
		bbq.erase(idx4, 5);
		bbq.insert(idx4, "#SHOCK#");
	}


	while (1) {


		int idx5 = bbq.find("SONY", a);
		if (idx5 == -1)break;
		a++;
		bbq.erase(idx5, 4);
		bbq.insert(idx5, "#NONY#");
	}
	cout << bbq;
}