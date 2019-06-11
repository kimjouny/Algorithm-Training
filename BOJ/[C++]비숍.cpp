#include <iostream>

using namespace std;

int N;
bool d[11][11];
int maxwhite = -1;
int maxBlack = -1;
bool lefts[30];
bool rights[30];

void ps() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void DFS(int cnt, int r, int c, bool color) {
	if (c >= N) {
		r++;
		if (c % 2 == 0) {
			c = 1;
		}
		else{
			c = 0;
		}
	}

	if (r == N) {
		if (color) {
			if (maxwhite < cnt)maxwhite = cnt;
		}
		else {
			if (maxBlack < cnt)maxBlack = cnt;
		}
		return;
	}

	if (d[r][c]&&!lefts[r+c]&&!rights[r-c+N-1]) {
		lefts[r + c] = true;
		rights[r - c + N - 1] = true;
		DFS(cnt + 1, r, c + 2, color);
		lefts[r + c] = false;
		rights[r - c + N - 1] = false;
	}

	DFS(cnt, r, c + 2, color);
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &d[i][j]);
		}
	}
}
int main() {
	init();
	DFS(0,0,0, false);
	DFS(0, 0, 1, true);
	printf("%d\n", maxBlack + maxwhite);
	return 0;
}