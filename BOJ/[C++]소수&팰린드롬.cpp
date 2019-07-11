#include <iostream>

using namespace std;

int N;
int length;
int nums[7];
void ps() {
	for (int i = length; i < 7; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}
bool chkPalen() {
	for (int i = 1; i <= (7 - length) / 2; i++) {
		if (nums[length + i - 1] != nums[7 - i]) {
			return false;
		}
	}
	return true;
}
bool chkUnique() {
	for (int i = 2; i < N; i++) {
		if (N % i == 0)return false;
	}
	return true;
}
void refine() {
	int div = 1000000;
	int num = N;
	bool first = true;
	int idx = 0;
	while (num > 0) {
		int divided = num / div;
		if (first) {
			if (divided != 0) {
				length = idx;
				first = false;;
			}
		}
		nums[idx] = divided;
		num %= div;
		div /= 10;
		idx++;
	}
}
void findMin() {
	if (N == 1 || N == 2) {
		printf("2\n");
		return;
	}
	while (N <= 10000000) {
		refine();
		if (chkPalen()) {
			if (chkUnique()) {
				printf("%d\n", N);
				break;
			}
		}
		for (int i = length; i < 7; i++) {
			nums[i] = 0;
		}
		N++;
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
}
int main() {
	init();
	findMin();
	return 0;
}