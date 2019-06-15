#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int N;
int noDeli,mostDeli;
int d[MAX][MAX];
int visit[MAX][MAX];
bool numlist[MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int numbering() {
	queue<pair<int, int>> q;
	int domnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] != 0&&visit[i][j]==-1) {
				++domnum;
				visit[i][j] = domnum;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int yy = q.front().first;
					int xx = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = yy + dy[k];
						int nx = xx + dx[k];
						if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
							if (visit[ny][nx] == -1 && d[ny][nx] != 0) {
								visit[ny][nx] = domnum;
								q.push(make_pair(ny, nx));
							}
						}
					}
				}
			}
		}
	}
	return domnum;
}
int cheeseDomain() {
	int cd = 1;
	for (int i = noDeli; i < mostDeli; i++) {
		if (!numlist[i])continue;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (d[j][k] == i)d[j][k] = 0;
				visit[j][k] = -1;
			}
		}
		int domains = numbering();
		cd = cd < domains ? domains : cd;
	}
	return cd;
}
void init() {
	cin >> N;
	mostDeli = -1;
	noDeli = 200;
	for (int i = 0; i < N; i++) {
		numlist[i] = false;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> d[i][j];
			numlist[d[i][j]] = true;
			noDeli = noDeli < d[i][j] ? noDeli : d[i][j];
			mostDeli = mostDeli < d[i][j] ? d[i][j] : mostDeli;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cout << '#' << t << ' ' << cheeseDomain() << "\n";
	}
	return 0;
}