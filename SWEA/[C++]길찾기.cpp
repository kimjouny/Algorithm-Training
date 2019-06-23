#include <iostream>
#include <queue>

using namespace std;
bool conn[100][100];
int dist[100];
int T, P;

bool findway() {
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int p = q.front();
		if (p == 99)return true;
		q.pop();

		for (int i = 0; i < 100; i++) {
			if (conn[p][i]) {
				if (dist[i] > dist[p] + i) {
					dist[i] = dist[p] + i;
					q.push(i);
				}
			}
		}
	}
	return false;
}
void init() {
	for (int i = 0; i < 100; i++) {
		dist[i] = 999999;
		for (int j = 0; j < 100; j++) {
			conn[i][j] = false;
		}
	}

	cin >> T >> P;
	int r, c;
	for (int i = 0; i < P; i++) {
		cin >> r >> c;
		conn[r][c] = true;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 10; i++) {
		init();
		cout << '#' << T << ' '<<findway()<<'\n';
	}
	return 0;
}