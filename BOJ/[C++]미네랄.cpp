#include <iostream>
#include <queue>

using namespace std;

int R, C;
int cave[101][101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int segment = 0;
queue<pair<int, int>> q;

void pts() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(cave[i][j])printf("x");
			else printf(".");
		}
		printf("\n");
	}
}
void fillOne() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cave[i][j])cave[i][j] = 1;
		}
	}
}

void falling() {
	for (int i = segment-1; i >= 2; i--) {
		int maxi = 0;
		int space = R;
		for (int c = 1; c <=C; c++) {
			int r = R;
			int sp = 0;
			bool isSeg = false;
			while (cave[r][c] != i&&r) {
				sp = !cave[r][c]? sp+1 : 0;
				r--;
			}
			if (r) {
				space = sp < space ? sp : space;
				maxi = r > maxi ? r : maxi;
			}
		}
		if (maxi==R)continue;
		if(space){
			for (int r = R; r >= 1; r -- ) {
				for (int c = 1; c <= C; c++) {
					if (cave[r][c] == i) {
						cave[r + space][c] = cave[r][c];
						cave[r][c] = 0;
					}
				}
			}
		}
	}
	
}
void BFS(int r, int c) {
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 1 && ny <= R&&nx >= 1 && nx <= C) {
				if (cave[ny][nx] == 1) {
					cave[ny][nx] = cave[r][c];
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}
void dividing() {
	segment = 2;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cave[i][j]==1) {
				cave[i][j] = segment;
				BFS(i,j);
				segment++;
			}
		}
	}
}

void breakRow(bool role,int row) {
	if (role) {
		for (int c = 1; c <= C; c++) {
			if (cave[row][c] == 1) {
				cave[row][c] = 0;
				return;
			}
		}
	}
	else {
		for (int c = C; c >=1; c--) {
			if (cave[row][c] == 1) {
				cave[row][c] = 0;
				return;
			}
		}
	}
	
}
void simul() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int row;
		scanf("%d", &row);
		breakRow(t%2,R-row+1);
		dividing();
		falling();
		fillOne();
	}
}
void init() {
	scanf("%d %d",&R,&C);
	char temp;
	for (int i = 1; i <= R; i++) {
		getchar();
		for (int j = 1; j <= C; j++) {
			scanf("%c", &temp);
			cave[i][j] = temp == '.' ? 0 : 1;
		}
	}
}
int main() {
	init();
	simul();
	pts();
	return 0;
}