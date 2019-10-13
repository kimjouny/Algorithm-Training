#include <iostream>
#include <queue>

using namespace std;

bool connection[101][101];
bool visit[101];
int last;

queue<int> q;
void printConnection() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++)cout << connection[i][j];
		cout << '\n';
	}
}

void BFS() {
	while (!q.empty()) {
		last = -1;
		int qsize = q.size();
		while (qsize--) {
			int number = q.front();
			last = number > last ? number : last;
			q.pop();

			for (int i = 1; i <= 100; i++) {
				if (i == number)continue;
				if (connection[number][i] && !visit[i]) {
					visit[i] = true;
					q.push(i);
				}
			}
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 100; i++) {
		visit[i] = false;
		for (int j = 1; j <= 100; j++) {
			connection[i][j] = false;
		}
	}

	int cycle, start;
	cin >> cycle >> start;
	visit[start] = true;
	q.push(start);

	for (int i = 0; i < cycle / 2; i++) {
		int r, c;
		cin >> r >> c;
		connection[r][c] = true;
	}
}

int main() {
	for (int t = 1; t <= 10; t++) {
		init();
		BFS();
		cout << '#' << t << ' ' << last << '\n';
	}
	return 0;
}