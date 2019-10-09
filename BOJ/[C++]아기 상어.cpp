#include <iostream>
#include <queue>
using namespace std;
int N;
int ocean[200][200];
int visit[200][200];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
struct SHARK {
	int y;
	int x;
	int size;
	int eat;
};
SHARK shark;
queue < pair<int, int>> q;
void visitset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)visit[i][j] = false;
	}
}
int FINDFISH() {
	int y=N; int x=N;
	while (!q.empty()) {
		int siz = q.size();
		while (siz--) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = p.first + dy[i];
				int nx = p.second + dx[i];
				if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
					if (visit[ny][nx])continue;
					if (ocean[ny][nx] == 0|| ocean[ny][nx] == shark.size) {
						visit[ny][nx] = visit[p.first][p.second]+1;
						q.push(make_pair(ny, nx));
					}
					else if (ocean[ny][nx] < shark.size ) {
						visit[ny][nx] = visit[p.first][p.second] + 1;
						if (y > ny) {
							y = ny;
							x = nx;
						}
						else if (y == ny&&nx<x) {
							x = nx;
						}
					}
				}
			}
		}
		if (y != N) {
			ocean[y][x] = 0;
			shark.eat += 1;
			if (shark.eat == shark.size) {
				shark.eat = 0;
				shark.size += 1;
			}
			int dist = visit[y][x]-1;
			shark.y = y;
			shark.x = x;

			while (!q.empty())q.pop();
			visitset();
			return dist;
		}
	}
	return 0;
}
int SHARKING() {
	int tick=0;
	while (1) {
		q.push(make_pair(shark.y, shark.x));
		visit[shark.y][shark.x] = 1;
		int checksum = FINDFISH();
		if (!checksum)break;
		tick += checksum;
	}
	return tick;
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ocean[i][j];
			if (ocean[i][j] == 9)
			{
				ocean[i][j] = 0;
				shark.y = i;
				shark.x = j;
				shark.eat = 0;
				shark.size = 2;
			}
		}
	}
}

int main() {
	init();
	cout<<SHARKING()<<endl;

	return 0;
}