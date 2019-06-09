#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

int N;
char d[MAX][MAX];
int visit[2][MAX][MAX];
int ey, ex;
bool edir;
struct STAMP {
	bool dir;
	int ypos;
	int xpos;
};
queue<STAMP> q;

void judge() {
	if (visit[edir][ey][ex] == -1) {
		printf("0\n");
	}
	else {
		printf("%d\n", visit[edir][ey][ex]);
	}
}
void goUP(bool dir, int y, int x) {
	if (dir) {
		if (y >= 1) {
			if (d[y-1][x-1] == '0'&&d[y-1][x] == '0'&&d[y-1][x+1] == '0') {
				if (visit[dir][y - 1][x] == -1) {
					visit[dir][y - 1][x] = visit[dir][y][x] + 1;
					q.push({ dir,y - 1,x });
				}
			}
		}
	}
	else {
		if (y >= 2) {
			if (d[y - 2][x] == '0'&&visit[dir][y-1][x]==-1) {
				visit[dir][y-1][x] = visit[dir][y][x] + 1;
				q.push({ dir,y - 1,x });
			}
		}
	}
}
void goDOWN(bool dir, int y, int x) {
	if (dir) {
		if (y + 1<N) {
			if (d[y + 1][x - 1] == '0'&&d[y + 1][x] == '0'&&d[y + 1][x + 1] == '0') {
				if (visit[dir][y + 1][x] == -1) {
					visit[dir][y + 1][x] = visit[dir][y][x] + 1;
					q.push({ dir,y + 1,x });
				}
			}
		}
	}
	else {
		if (y + 2<N) {
			if (d[y + 2][x] == '0'&&visit[dir][y+1][x] == -1) {
				visit[dir][y + 1][x] = visit[dir][y][x] + 1;
				q.push({ dir,y + 1,x });
			}
		}
	}
}
void goLEFT(bool dir, int y, int x) {
	if (dir) {
		if (x >= 2) {
			if (d[y][x - 2] == '0'&&visit[dir][y][x - 1] == -1) {
				visit[dir][y][x - 1] = visit[dir][y][x] + 1;
				q.push({ dir,y,x - 1 });
			}
		}
	}
	else {
		if (x >= 1) {
			if (d[y+1][x-1] == '0'&&d[y][x-1] == '0'&&d[y-1][x-1] == '0') {
				if (visit[dir][y][x - 1] == -1) {
					visit[dir][y][x - 1] = visit[dir][y][x] + 1;
					q.push({ dir,y,x - 1 });
				}
			}
		}
	}
}
void goRIGHT(bool dir, int y, int x) {
	if (dir) {
		if (x+2<N) {
			if (d[y][x+2] == '0'&&visit[dir][y][x+1] == -1) {
				visit[dir][y][x + 1] = visit[dir][y][x] + 1;
				q.push({ dir,y,x + 1 });
			}
		}
	}
	else {
		if (x +1<N) {
			if (d[y + 1][x + 1] == '0'&&d[y][x + 1] == '0'&&d[y - 1][x + 1] == '0') {
				if (visit[dir][y][x + 1] == -1) {
					visit[dir][y][x + 1] = visit[dir][y][x] + 1;
					q.push({ dir,y,x + 1 });
				}
			}
		}
	}
}
void goTILT(bool dir, int y, int x) {
	if (dir) {
		if (visit[false][y][x] != -1)return;
		if (y >= 1 && y + 1 < N) {
			if (d[y-1][x-1] == '0'&&d[y-1][x] == '0'&&d[y-1][x+1] == '0'&&d[y+1][x-1] == '0'&&d[y+1][x] == '0'&&d[y+1][x+1] == '0') {
				visit[false][y][x] = visit[true][y][x] + 1;
				q.push({false,y,x});
			}
		}
	}
	else {
		if (visit[true][y][x] != -1)return;
		if (x >= 1 && x + 1 < N) {
			if (d[y + 1][x - 1] == '0'&&d[y][x - 1] == '0'&&d[y - 1][x - 1] == '0'&&d[y + 1][x + 1] == '0'&&d[y][x + 1] == '0'&&d[y - 1][x + 1] == '0') {
				visit[true][y][x] = visit[false][y][x] + 1;
				q.push({ true,y,x });
			}
		}
	}
}
void BFS() {
	while (!q.empty()) {
		int ddir = q.front().dir;
		int yy = q.front().ypos;
		int xx = q.front().xpos;
		q.pop();

		if (yy == ey&&xx == ex) {
			if (edir == ddir) {
				return;
			}
		}
		goUP(ddir,yy,xx);
		goDOWN(ddir,yy,xx);
		goLEFT(ddir,yy,xx);
		goRIGHT(ddir,yy,xx);
		goTILT(ddir,yy,xx);
	}
}
void defStamp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] == 'B') {
				if (d[i][j + 1] == 'B'&&j + 1<N) {
					d[i][j] = '0';
					d[i][j + 1] = '0';
					d[i][j + 2] = '0';
					visit[true][i][j + 1] = 0;
					q.push({true,i,j+1});
					}
				else if (d[i + 1][j] == 'B'&&i + 1 < N) {
					d[i][j] = '0';
					d[i+1][j] = '0';
					d[i+2][j] = '0';
					visit[false][i+1][j] = 0;
					q.push({ false,i+1,j});
				}
			}
			else if (d[i][j] == 'E') {
				if (d[i][j + 1] == 'E'&&j + 1<N) {
					edir = true;
					d[i][j] = '0';
					d[i][j + 1] = '0';
					d[i][j + 2] = '0';
					ey = i;
					ex = j+1;
				}
				else if (d[i + 1][j] == 'E'&&i + 1 < N) {
					edir = false;
					d[i][j] = '0';
					d[i + 1][j] = '0';
					d[i + 2][j] = '0';
					ey = i+1;
					ex = j;
				}
			}
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < N; j++) {
			scanf("%c", &d[i][j]);
			visit[0][i][j] = -1;
			visit[1][i][j] = -1;
		}
	}
}

int main() {
	init();
	defStamp();
	BFS();
	judge();
	return 0;
}