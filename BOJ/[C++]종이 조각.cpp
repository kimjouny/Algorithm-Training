#include<iostream>
#include<cmath>
using namespace std;
int N, M;
int d[5][5];
bool visit[5][5];
int answer = -1;
void DFS(int r, int c, int summ) {
	if (c == M) { r += 1; c = 0; }
	if (visit[r][c]) { DFS(r, c + 1,summ); return; }
	if (r == N) { answer=answer<summ?summ:answer; return; }

	for (int i = M; i >= 1; i--) {
		if (c + i - 1 < M) {
			bool isavail = true;
			for (int j = 0; j < i; j++) {
				if (visit[r][c+j]) { isavail = false; break; }
			}
			if (isavail) {
				int adds = 0;
				for (int j = 0; j < i; j++) {
					adds += d[r][c + j]*pow(10,i-j-1);
					visit[r][c + j] = true;
				}
				DFS(r, c + i, summ + adds);
				for (int j = 0; j < i; j++) {
					visit[r][c + j] = false;
				}
			}
		}
	}

	for (int i = N; i >= 1; i--) {
		if (r + i - 1 < N) {
			bool isavail = true;
			for (int j = 0; j < i; j++) {
				if (visit[r+j][c]) { isavail = false; break; }
			}
			if (isavail) {
				int adds = 0;
				for (int j = 0; j < i; j++) {
					adds += d[r+j][c] * pow(10, i - j - 1);
					visit[r+j][c] = true;
				}
				DFS(r, c +1, summ + adds);
				for (int j = 0; j < i; j++) {
					visit[r+j][c] = false;
				}
			}
		}
	}
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &d[i][j]);
		}
	}
}
int main() {
	init();
	DFS(0, 0, 0);
	cout << answer << '\n';
	return 0;
}