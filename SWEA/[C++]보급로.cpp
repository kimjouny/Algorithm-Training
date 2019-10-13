#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;

int N;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

//need initiation
int visit[101][101];
bool D[101][101];

void BFS() {
	q.push(MP(0, 0));
	visit[0][0] = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy+ dy[i];
			int nx = cx+ dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
				int dist = visit[cy][cx] + D[ny][nx];
				if (dist < visit[ny][nx]) { 
					q.push(MP(ny, nx)); 
					visit[ny][nx] = dist;
				}
			}
		}
	}
}
void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 1000;
			scanf("%1d", &D[i][j]);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		init();
		BFS();
		printf("#%d %d\n", i, visit[N - 1][N - 1]);
	}
	return 0;
}
