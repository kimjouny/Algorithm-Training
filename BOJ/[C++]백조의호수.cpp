#include <iostream>
#include <queue>

using namespace std;

int R, C;
char gracial[1501][1501];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int days;
bool visit[1501][1501];
int sy, sx;
queue<pair<int, int>> SW,NSW,ice;

void melting() {
	int isz = ice.size();
	while (isz--) {
		int yy = ice.front().first;
		int xx = ice.front().second;
		ice.pop();
		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < R&&nx >= 0 && nx < C) {
				if (gracial[ny][nx] == 'X') {
					gracial[ny][nx] = '.';
					ice.push(make_pair(ny, nx));
				}
			}
		}
	}
}
bool isMatch() {
	while (!SW.empty()) {
		int yy = SW.front().first;
		int xx = SW.front().second;
		SW.pop();
		if (gracial[yy][xx] == 'o') {
			continue;
		}
		else {
			gracial[yy][xx] = 'o';
		}
		if (yy == sy&&xx == sx) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < R&&nx >= 0 && nx < C) {
				if (gracial[ny][nx] == 'X') { NSW.push(make_pair(ny, nx)); }
				else if (gracial[ny][nx] == '.') {
					SW.push(make_pair(ny, nx));
				}
			}
		}
	}
	return false;
}
void conn() {
	days = 0;
	while(!isMatch()) {
		days++;
		melting();
		SW = NSW;
		while (!NSW.empty()) {
			NSW.pop();
		}
	}
}
void init() {
	bool swanidx = true;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++){
		getchar();
		for (int j = 0; j < C; j++) {
			scanf("%c", &gracial[i][j]);
			if (gracial[i][j] == '.') {
				ice.push(make_pair(i, j));
			}
			else if (gracial[i][j] == 'L') {
				ice.push(make_pair(i, j));
				gracial[i][j] = '.';
				if (swanidx) {
					SW.push(make_pair(i, j));
					swanidx=false;
				}
				else {
					sy = i;
					sx = j;
				}
			}
		}
	}

}
int main() {
	init();
	conn();
	printf("%d\n", days);
	return 0;
}