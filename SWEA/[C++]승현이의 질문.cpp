#include <iostream>
#define MAX 1000001
using namespace std;

int N;
int nums[MAX];
int nsum[MAX];
int answer, lleft, rright;
int parametricSearch() {
	int mid;
	while (lleft <= rright) {
		mid = (lleft + rright) >> 1;
		if (mid <= nsum[mid]) {
			answer = answer < mid ? mid : answer;
			lleft = mid + 1;
		}
		else {
			rright = mid - 1;
		}
	}
	return answer;
}
void paramSum() {
	nsum[MAX - 1] = nums[MAX - 1];
	for (int i = MAX - 2; i >= 0; i--) {
		nsum[i] = nsum[i + 1] + nums[i];
	}
}
void init() {
	rright = -1;
	for (int i = 0; i<MAX ; i++) {
		nums[i] = 0;
	}
	cin >> N;
	int temp;
	for (int i=lleft=answer= 0; i < N; i++) {
		cin >> temp;
		nums[temp]++;
		rright = rright < temp ? temp : rright;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		paramSum();
		cout <<"#"<<t<<" "<< parametricSearch()<< "\n";
	}
	return 0;
}