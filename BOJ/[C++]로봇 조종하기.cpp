#include <iostream>
#define MAX 1003

using namespace std;

int N, M;
int d[MAX][MAX];
int dp[MAX][MAX];
int lefts[MAX];
int rights[MAX];

int getMax(int a, int b) { return a > b ? a : b; }
void DP() {
	dp[1][1] = d[1][1];
	for (int i = 2; i <= M; i++) {
		dp[1][i] = dp[1][i - 1] + d[1][i];
	}
	for (int i = 2; i <= N; i++) { 

		for (int j = 1; j <= M; j++) {
			if (j == 1) {
				lefts[j] = dp[i - 1][j] + d[i][j];
			}
			else {
				lefts[j] = getMax(dp[i - 1][j], lefts[j - 1]) + d[i][j];
			}	
		}
		for (int j = M; j >= 1; j--) {
			if (j == M) {
				rights[j] = dp[i - 1][j] + d[i][j];
			}
			else {
				rights[j] = getMax(dp[i - 1][j], rights[j + 1]) + d[i][j];
			}
		}
		for (int j = 1; j <= M; j++) {
			dp[i][j] = getMax(lefts[j], rights[j]);
		}
	}
	printf("%d\n", dp[N][M]);
}
void init() {
	ios::sync_with_stdio(false);
	scanf_s("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%d", &d[i][j]);
		}
	}
}
int main() {
	init();
	DP();
	return 0;
}