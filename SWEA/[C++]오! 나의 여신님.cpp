#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

int T,N,M;
char mp[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
queue < pair<int, int>> suyeon;
queue < pair<int, int>> devil;
bool arrived;
int answer;
void devilExpand() {
	int ds=devil.size();
	while (ds--) {
		int yy = devil.front().first;
		int xx = devil.front().second;
		devil.pop();

		for (int i = 0; i < 4; i++){
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (mp[ny][nx] == '.') {
					mp[ny][nx] = '*';
					devil.push(make_pair(ny, nx));
				}
			}
		}
	}
}
void suyeonGo() {
	
	int ds = suyeon.size();
	while (ds--) {
		int yy = suyeon.front().first;
		int xx = suyeon.front().second;
		suyeon.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (mp[ny][nx] == '*')continue;

				if (mp[ny][nx] == 'D') {
					arrived = true;
					answer = dist[yy][xx] + 1;
					return;
				}
				else if (mp[ny][nx] == '.'&&dist[ny][nx]==-1) {
					dist[ny][nx] = dist[yy][xx] + 1;
					suyeon.push(make_pair(ny, nx));
				}
			}
		}
	}
}
void simul() {
	while (!suyeon.empty()) {
		devilExpand();
		suyeonGo();
		if (arrived)return;
	}
}
void init() {
	answer = 999999;
	arrived = false;
	while (!suyeon.empty()) {
		suyeon.pop();
	}
	while (!devil.empty()) {
		devil.pop();
	}
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
        getchar();
		for (int j = 0; j < M; j++) {
			dist[i][j] = -1;
			scanf("%1c", &mp[i][j]);
			if (mp[i][j] == 'S') {
				suyeon.push(make_pair(i, j));
				dist[i][j] = 0;
				mp[i][j] = '.';
			}
			else if (mp[i][j] == '*') {
				devil.push(make_pair(i, j));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		init();
		simul();
		if (arrived)printf("#%d %d\n", t, answer);
		else {
			printf("#%d GAME OVER\n", t);
		}
	}
	return 0;
}