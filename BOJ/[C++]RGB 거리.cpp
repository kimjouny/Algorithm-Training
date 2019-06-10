#include <iostream>
#define MAX 1003000
using namespace std;

int N;
int cost[1001][3];

void findMin() {
	int answer = MAX;
	for (int i = 0; i < 3; i++) {
		if (answer > cost[N - 1][i])answer = cost[N - 1][i];
	}
	printf("%d\n", answer);
}
void painting() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = MAX;
			for (int k = 0; k < 3; k++) {
				if (j == k)continue;
				if (temp > cost[i - 1][k])temp = cost[i - 1][k];
			}
			cost[i][j] += temp;
		}
	}
}
void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
}
int main() {
	init();
	painting();
	findMin();
	return 0;
}