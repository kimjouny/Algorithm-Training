#include <iostream>
using namespace std;

bool maps[33][33];
long long dp[3][33][33];
int N;
long long DFS(int dir, int yy, int xx);

void goHori(int dir, int yy, int xx) {
	if (xx + 1 < N && !maps[yy][xx + 1]) {
		dp[dir][yy][xx] += DFS(0, yy, xx + 1);
	}
}
void goVerti(int dir, int yy, int xx) {
	if (yy + 1< N && !maps[yy + 1][xx]) {
		dp[dir][yy][xx] += DFS(2, yy + 1, xx);
	}
}
void goDiagonal(int dir, int yy, int xx) {
	if (yy + 1 < N&&xx + 1 < N) {
		if (!maps[yy + 1][xx + 1] && !maps[yy + 1][xx] && !maps[yy][xx + 1]) {
			dp[dir][yy][xx] += DFS(1, yy + 1, xx + 1);
		}
	}

}

long long DFS(int dir, int yy, int xx) {
	if (dp[dir][yy][xx] != -1)return dp[dir][yy][xx];

	if (yy == N - 1 && xx == N - 1)return 1;

	dp[dir][yy][xx] = 0;

	if (dir == 0) {
		goHori(dir, yy, xx);
	}
	else if (dir == 1) {
		goHori(dir, yy, xx);
		goVerti(dir, yy, xx);
	}
	else if (dir == 2) {
		goVerti(dir, yy, xx);
	}

	goDiagonal(dir, yy, xx);

	return dp[dir][yy][xx];
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}
int main() {
	init();
	DFS(0, 0, 1);
	long long answer = DFS(0, 0, 1);
	printf("%lld\n", answer);
	return 0;
}
