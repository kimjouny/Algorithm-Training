#include <iostream>
#include <queue>
#define MAX 21
#define PA make_pair

using namespace std;

int N, M;
int mp[MAX][MAX];
int d[2][MAX][MAX];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void solve() {
	if (d[0][N - 1][N - 1] > d[1][N - 1][N - 1]) {
		printf("%d\n", d[1][N - 1][N - 1]);
	}
	else {
		printf("%d\n", d[0][N - 1][N - 1]);
	}
}
int getDist(int dest, int beg) {
	int divv = (beg+1) % dest;
	if (divv == 0)return beg + 1;
	else {
		return beg + 1 + dest - divv;
	}
}
void BFS() {
	queue<pair<pair<bool, bool>, pair<int, int>>> q;
	q.push(PA(PA(false,false), PA(0,0)));
	d[false][0][0] = 0;
	
	while (!q.empty()) {
		int yy = q.front().second.first;
		int xx = q.front().second.second;
		bool bridge = q.front().first.first;
		bool croseed = q.front().first.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
				if (mp[ny][nx] == -1)continue;
				if (mp[ny][nx] == 1) {
					if (d[bridge][ny][nx] > d[bridge][yy][xx] + 1) {
						d[bridge][ny][nx] = d[bridge][yy][xx] + 1;
						q.push(PA(PA(bridge, false), PA(ny, nx)));
					}
				}
				else if (mp[ny][nx] > 1) {
					if (!croseed) {
						int distance = getDist(mp[ny][nx], d[bridge][yy][xx]);
						if (d[bridge][ny][nx] >distance ) {
							d[bridge][ny][nx] = distance;
							q.push(PA(PA(bridge,true), PA(ny,nx)));
						}
					}
				}
				else if (mp[ny][nx] == 0) {
					if (!bridge && !croseed) {
						int distance = getDist(M, d[bridge][yy][xx]);
						if (d[bridge][ny][nx] >distance) {
							d[1][ny][nx] = distance;
							q.push(PA(PA(true, true), PA(ny, nx)));
						}
					}
				}
			}
		}

	}
}
void findCross() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 0) {
				bool hori = false;
				bool verti = false;
				for (int k = 0; k < 2; k++) {
					int ny = i + dy[k];
					if (ny >= 0 && ny < N) {
						if (mp[ny][j] != 1)verti = true;
					}	
				}
				for (int k = 2; k < 4; k++) {
					int nx = j + dx[k];
					if (nx >= 0 && nx < N) {
						if (mp[i][nx] != 1)hori = true;
					}
				}
				if (hori&&verti)mp[i][j] = -1;
			}
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &mp[i][j]);
			d[1][i][j] = 999999;
			d[0][i][j] = 999999;
		}
	}
}
int main() {
	init();
	findCross();
	BFS();
	solve();
	return 0;
}