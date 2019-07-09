#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool d[1001][1001];
int visit[2][1001][1001];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
struct P {
	int y;
	int x;
	bool crush;
};

queue<P> q;

void BFS() {
	q.push({0,0,false});
	visit[0][0][0] = true;
	while (!q.empty()) {
		int yy = q.front().y;
		int xx = q.front().x;
		bool crushed = q.front().crush;
		q.pop();

		if (N - 1 == yy&&M - 1 == xx)return;

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (d[ny][nx] == 0&&visit[crushed][ny][nx]==0) {
					visit[crushed][ny][nx] = visit[crushed][yy][xx] + 1;
					q.push({ny,nx,crushed});
				}
				else if(!crushed&&d[ny][nx]==1&&visit[true][ny][nx]==0){
					visit[true][ny][nx] = visit[crushed][yy][xx] + 1;
					q.push({ ny,nx,true });
				}
			}

		}

	}
}
void init() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &d[i][j]);
		}
	}
}
int main() {
	init();
	BFS();
	int answer = visit[true][N - 1][M - 1] > visit[false][N - 1][M - 1] ? visit[true][N - 1][M - 1] : visit[false][N - 1][M - 1];
	if (answer == 0) {
		answer = -1;
	}
	printf("%d\n", answer);
	return 0;
}