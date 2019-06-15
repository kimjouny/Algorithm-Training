#include <iostream>
#include <vector>
using namespace std;

int N;
int d[301][301];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

void killAround(int r, int c) {
	if (d[r][c] == -1)return;
	d[r][c] = -1;
	for (int i = 0; i < 8; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
			if (d[ny][nx] == 0) {
				killAround(ny, nx);
			}
			else {
				d[ny][nx] = -1;
			}
		}
	}
}
int getSingle() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] > 0)cnt++;
		}
	}
	return cnt;
}
int getCount() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] == 0) {
				killAround(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}
void setNum() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] == -2) {
				d[i][j] = 0;
				for (int k = 0; k < 8; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
						if (d[ny][nx] == -3) {
							d[i][j]++;
						}
					}
				}
			}
		}
	}
}
void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char temp;
		getchar();
		for (int j = 0; j < N; j++) {
			scanf("%c", &temp);
			if (temp == '.') {
				d[i][j] = -2;
			}
			else {
				d[i][j] = -3;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		init();
		setNum();
		printf("#%d %d\n", t,getCount()+getSingle());
	}
	return 0;
}