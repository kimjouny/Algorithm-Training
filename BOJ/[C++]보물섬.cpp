#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
char d[51][51];
bool visit[51][51];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int QY[2500];
int QX[2500];
int QC[2500];
int sq, eq;
int maxi;
int answer = -1;

void BFS() {
	while (sq != eq) {
		int yy = QY[++eq];
		int xx = QX[eq];
		int cnt = QC[eq];
		if (maxi < cnt) {
			maxi = cnt;
		}
		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (d[ny][nx] == 'L' && !visit[ny][nx]) {
					visit[ny][nx] = true;
					QY[++sq] = ny;
					QX[sq] = nx;
					QC[sq] = cnt + 1;
				}
			}
		}
	}

}


void fluidfill() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]&& d[i][j] == 'L') {
				maxi = -1;
				visit[i][j] = true;
				sq = eq = -1;
				QY[++sq] = i;
				QX[sq] = j;
				QC[sq] = 0;
				BFS();

				memset(visit,0,sizeof(visit));

				if(answer < maxi)answer=maxi;
			}
		}
	}
}
void init() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &d[i][j]);
		}
	}
}
int main() {
	init();
	fluidfill();
	printf("%d\n", answer);
	return 0;
}