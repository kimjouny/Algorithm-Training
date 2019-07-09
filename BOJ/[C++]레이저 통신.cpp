#include <iostream>
#include <queue>
using namespace std;


int N, M;
char d[101][101];
int visit[101][101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			while (ny >= 0 && ny < N&&nx >= 0 && nx < M && d[ny][nx] != '*') {
				if (d[ny][nx] == 'C') { printf("%d\n", visit[yy][xx] - 1); return; }
				if(visit[ny][nx]==0){
					q.push(make_pair(ny, nx));
					visit[ny][nx] = visit[yy][xx] + 1;
				}
				
				ny += dy[i];
				nx += dx[i];
			}
		}
	}
}
void init() {
	scanf("%d %d", &M, &N);
	int cidx = 0;
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &d[i][j]);
			if (d[i][j] == 'C') {
				if (cidx == 0) {
					cidx++;
					d[i][j] = '.';
					visit[i][j] = 1;
					q.push(make_pair(i, j));
				}
			}
		}
	}
}
int main() {
	init();
	BFS();
	return 0;
}