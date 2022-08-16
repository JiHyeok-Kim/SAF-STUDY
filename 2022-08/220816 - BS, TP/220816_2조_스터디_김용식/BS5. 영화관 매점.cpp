#include <iostream>
#include <vector>

using namespace std;
vector<long long> movie;
long long N=0, M=0;

long long isTime(long long c) {
	long long time = 0;
	for (int i = 0; i < movie.size(); i++) {
		time += c / movie[i];
	}
	if (time >= M) {
		return time;
	}
	return time;
}

long long bs(long long s, long long e) {
	long long last = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long time = isTime(mid);
		if (time < M) {
			last = mid;
			s = mid +1 ;	
		}
		else {
			e = mid - 1;
		}
	}
	return last;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		movie.push_back(temp);
	}
	
	long long ret = bs(1, 21e8);

	cout << (ret+1);
	return 0;
}