#include <iostream>
#include <queue>
#define MAX 100
using namespace std;


struct TOMATO {
	int zp;
	int yp;
	int xp;
};

int dz[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 1,-1,0,0,0,0 };

int d[MAX][MAX][MAX];
int N, M, H;
queue<TOMATO> q;

bool fullTomato() {
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (d[h][i][j] == 0)return false;
			}
		}
	}
	return true;
}
int BFS() {
	int round = -1;
	while (!q.empty()) {
		round++;
		int siz = q.size();
		while (siz--) {
			int zz = q.front().zp;
			int yy = q.front().yp;
			int xx = q.front().xp;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nz = zz + dz[i];
				int ny = yy + dy[i];
				int nx = xx + dx[i];
				if (nz >= 0 && nz < H&&ny >= 0 && ny < N&&nx >= 0 && nx < M) {
					if (d[nz][ny][nx] == 0 ) {
						d[nz][ny][nx] = 1;
						q.push({nz,ny,nx});
					}
				}
			}
		}
	}
	return round;
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d %d %d", &M, &N, &H);
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &d[h][i][j]);
				if (d[h][i][j] == 1) {
					q.push({ h,i,j });
				}
			}
		}
	}
}
int main() {
	init();
	int answer=BFS();
	if (fullTomato()) {
		printf("%d\n", answer);
	}
	else {
		printf("-1\n");
	}
	return 0;
}