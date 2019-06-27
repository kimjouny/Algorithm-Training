#include <iostream>

using namespace std;

int d[101][101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int QX[10001];
int QY[10001];
int sq, eq;
bool finded;
void BFS() {
	while (sq != eq) {
		int yy = QY[++eq];
		int xx = QX[eq];

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < 100 && nx >= 0 && nx < 100) {
				if (d[ny][nx] == 3) {
					finded = true;
					return;
				}
				else if (d[ny][nx] == 0) {
					d[ny][nx] = -1;
					QY[++sq] = ny;
					QX[sq] = nx;
				}
			}
		}
	}
}
void init() {
	finded = false;
	sq = eq = -1;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			scanf("%1d", &d[i][j]);
			if (d[i][j] == 2) {
				QY[++sq] = i;
				QX[sq] = j;
				d[i][j] = -1;
			}
		}
	}
}
int main() {
	int T;
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &T);
		init();
		BFS();
		printf("#%d %d\n", t, finded);
	}
	return 0;
}