#include <iostream>
#include <queue>
#include <map>
#define MAX 51
using namespace std;

int N, M;
bool d[4][MAX][MAX];
int domain[MAX][MAX];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
int pows[4] = { 1,2,4,8 };
int walls = 1;
int maxcnt = -1;
int maxunite = -1;
queue<pair<int, int>> q;
map<int, int>layer;

void getINFO() {
	printf("%d\n%d\n%d\n", walls - 1, maxcnt, maxunite);
}
void unite() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
					if (domain[i][j] != domain[ny][nx]) {
						int summ = layer[domain[i][j]] + layer[domain[ny][nx]];
						if (summ > maxunite)maxunite = summ;
					}
				}
			}
		}
	}
}
void BFS(int y, int x) {
	domain[y][x] = walls;
	q.push(make_pair(y, x));
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			if (d[k][yy][xx])continue;
			int ny = yy + dy[k];
			int nx = xx + dx[k];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (domain[ny][nx] == 0) {
					domain[ny][nx] = walls;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	layer[walls] = cnt;
	if (cnt > maxcnt)maxcnt = cnt;
}
void numbering() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (domain[i][j] == 0) {
				BFS(i,j);
				walls++;
			}
		}
	}
}
void parseWall(int y, int x, int num) {
	for (int i = 3; i >= 0; i --) {
		if (num >= pows[i]) {
			d[i][y][x] = true;
			num -= pows[i];
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d %d", &M, &N);
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			parseWall(i,j,temp);
		}
	}
}
int main() {
	init();
	numbering();
	unite();
	getINFO();
	return 0;
}