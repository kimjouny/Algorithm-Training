#include <iostream>
#define MAX 101
using namespace std;

int d[MAX][MAX];
int N, M;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int points[2][2][2];
int pipes;
bool priorFlag;
int sq, eq;
int answer = 9999999;
struct CONN {
	int x, y, bf;
}Q[MAX*MAX];

void lining() {
	for (int i = 0; i <=M; i++) {
		for (int j = 0; j <= N; j++) {
			d[i][j] = -1;
		}
	}

	int idx = eq;
	while (idx != -1) {
		d[Q[idx].y][Q[idx].x] = -2;
		idx = Q[idx].bf;
	}
}
void preBFS() {
	sq = eq = -1;
	Q[++sq].x = points[priorFlag][0][0];
	Q[sq].y = points[priorFlag][0][1];
	Q[sq].bf = -1;
	while (sq != eq) {
		int xx = Q[++eq].x;
		int yy = Q[eq].y;

		if (xx == points[priorFlag][1][0] && yy == points[priorFlag][1][1]) {
			pipes = d[yy][xx];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx <= N&&ny >= 0 && ny <= M) {
				if (d[ny][nx] == -1) {
					d[ny][nx] = d[yy][xx] + 1;
					Q[++sq].x = nx;
					Q[sq].y = ny;
					Q[sq].bf = eq;
				}

			}
		}
	}
}
void init() {
	pipes = 9999999;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			d[i][j] = -1;
		}
	}

	d[points[!priorFlag][0][1]][points[!priorFlag][0][0]] = -2;
	d[points[!priorFlag][1][1]][points[!priorFlag][1][0]] = -2;
	d[points[priorFlag][0][1]][points[priorFlag][0][0]] = 0;
}
void conn() {
	init();
	preBFS();
	if (pipes != 9999999) {
		lining();
		priorFlag = !priorFlag;
		d[points[priorFlag][0][1]][points[priorFlag][0][0]] = pipes;
		preBFS();
		if(d[points[priorFlag][1][1]][points[priorFlag][1][0]] != -1){
            answer = pipes < answer ? pipes : answer;
        }
    }
}
void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> points[i][j][k];
			}
		}
	}
}
int main() {
	input();
	priorFlag = false;
	conn();
	priorFlag = true;
	conn();
	if (answer == 9999999) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}