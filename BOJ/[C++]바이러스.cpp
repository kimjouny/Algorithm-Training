#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool d[101][101];
bool linked[101];
int answer = 0;
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 2; i <= N; i++) {
			if (d[num][i] && !linked[i]) {
				linked[i] = true;
				q.push(i);
				answer++;
			}
		}
	}
}
void spread() {
	linked[1] = true;
	for (int i = 2; i <= N; i++) {
		if (d[1][i]) { q.push(i); linked[i] = true; answer++; }
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		d[r][c] = true;
		d[c][r] = true;
	}

}
int main() {
	init();
	spread();
	BFS();
	cout << answer << '\n';
	return 0;
}