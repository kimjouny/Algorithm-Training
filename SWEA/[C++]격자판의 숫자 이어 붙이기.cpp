#include <iostream>
#include <cmath>
using namespace std;
int d[4][4];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
bool visit[10000000];
int answer;
long long summ;

void DFS(int cnt, int r, int c) {
	if (cnt == 7) {
		if (!visit[summ]) {
			answer++;
			visit[summ] = true;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];

		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			summ += d[ny][nx] * pow(10, 6 - cnt);
			DFS(cnt + 1, ny, nx);
			summ -= d[ny][nx] * pow(10, 6 - cnt);
		}
	}

}
void init() {
	answer = 0;
	for (long long i = 0; i < 10000000; i++) {
		visit[i] = false;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			summ = d[i][j] * 1000000;
			DFS(1, i, j);
		}
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cout <<'#'<<t<<' '<<answer<< '\n';
	}
	return 0;
}