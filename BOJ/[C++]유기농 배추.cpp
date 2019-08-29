#include <iostream>
#include <queue> 

using namespace std;

int T;
int field[50][50];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int N, M, K;
queue<pair<int, int>> q;

void BFS(int r, int c) {
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i< 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (field[ny][nx] == 1) {
					field[ny][nx] = field[r][c];
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int worm() {
	int needed = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 1) {
				field[i][j] = needed++;
				BFS(i,j);
			}
		}
	}
	return needed-2;
}

void fieldInit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			field[i][j] = 0;
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> M >> N >> K;
		fieldInit();
		int r, c;
		for (int k = 0; k < K; k++) {
			cin >> c >> r;
			field[r][c] = 1;
		}
		cout <<worm()<< '\n';
	}
}

int main() {
	init();
	return 0;
}