#include <iostream>
#define MAX 501

using namespace std;

int N, M;
int d[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int DP(int y, int x) {
	if (y == N - 1 && x == M - 1)return 1;
	if (dist[y][x] != -1)return dist[y][x];
	dist[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
			if (d[ny][nx] < d[y][x]) {
				dist[y][x] += DP(ny, nx);
			}
		}
	}
	return dist[y][x];
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &d[i][j]);
			dist[i][j] = -1;
		}
	}
}
int main() {
	init();
	printf("%d\n", DP(0, 0));
	return 0;
}