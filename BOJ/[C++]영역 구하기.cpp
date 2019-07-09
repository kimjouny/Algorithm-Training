#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int d[102][102];
int N, M, K;
int region = 0;
queue<pair<int, int>> q;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
vector<int> v;

int BFS() {
	int addon = 0;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy+dy[i];
			int nx = xx+dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (d[ny][nx] == 0) {
					d[ny][nx] = region;
					addon++;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return addon;
}
void fluidfill() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (d[i][j] == 0) {
				d[i][j] = ++region;
				q.push(make_pair(i, j));
				v.push_back(1 + BFS());
			}
		}
	}
}
void draw() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			d[i][j] = -1;
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		draw();
	}

	
}
int main() {
	init();
	fluidfill();
	sort(v.begin(), v.end());
	cout << region<< '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
}