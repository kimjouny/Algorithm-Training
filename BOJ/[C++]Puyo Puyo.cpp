#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;

char field[12][6];
bool visit[12][6];
int bomb = 0;
int dy[4] = {1,0,-1,0};
int dx[4] = { 0,1,0,-1 };

void drop() {
	for (int i = 0; i < 6; i++) {
		for (int j = 10; j >= 0; j--) {
			if (field[j][i] == '.')continue;
			int idx = j;
			while (field[idx+1][i] == '.'&&idx < 12) {
				idx++;
			}
			if (idx != j) {
				field[idx][i] = field[j][i];
				field[j][i] = '.';
			}
		}
	}
	
}
void justdel() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visit[i][j] = false;
		}
	}
}
void popping() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j]) {
				field[i][j] = '.';
				visit[i][j] = false;
			}
		}
	}
}
bool destroy() {
	bool ispop = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (field[i][j] != '.') {
				queue < pair<int, int> > q;
				visit[i][j] = true;
				int cnt = 1;
				q.push(MP(i, j));
				while (!q.empty()) {
					int yy = q.front().first;
					int xx = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = yy + dy[k];
						int nx = xx + dx[k];

						if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6) {
							if (!visit[ny][nx] && field[ny][nx] == field[yy][xx]) {
								q.push(MP(ny, nx));
								cnt++;
								visit[ny][nx] = true;
							}
						}
					}
				}
				if (cnt >= 4) {
					ispop = true;
					popping();
				}
				else {
					justdel();
				}

			}
		}
	}

	return ispop;
}
void PUYO() {
	while (destroy()) {
		bomb++;
		drop();
	}
}
void init() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%c", &field[i][j]);
		}
		getchar();
	}
}
int main() {
	init();
	PUYO();
	printf("%d\n", bomb);
	return 0;
}