#include <iostream>
#include <cmath>
using namespace std;

int enemy[16][16];
int reps[16][16];
int arch[3];
int N, M, D;
int answer = 0;

void rolling() {
	for (int i = N-2; i >=0; i--) {
		for (int j = 0; j < M; j++) {
			reps[i + 1][j] = reps[i][j];
		}
	}
	for (int j = 0; j < M; j++)reps[0][j] = 0;
}
int selectKill() {
	int kills = 0;
	for (int a = 0; a < 3; a++) {
		int mindist = 999999;
		int xx = 0; int yy = 0;
		for (int j = 0; j < M; j++) {
			for (int i = 0; i <N; i++) {
				if (reps[i][j] != 0) {
					int temp = abs(N - i) + abs(arch[a] - j);
					if (mindist > temp&&temp <= D) {
						mindist = temp;
						yy = i;
						xx = j;
					}
				}
			}
		}
		if (mindist != 999999) {
			reps[yy][xx] += 1;
		}	
	}
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (reps[i][j] > 1) {
				kills++;
				reps[i][j] = 0;
			}
		}
	}
	return kills;
}
void copying() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			reps[i][j] = enemy[i][j];
		}
	}
}
void killEnem() {
	int summ = 0;
	copying();
	for (int i = 0; i < N; i++) {
		summ+=selectKill();
		rolling();
	}
	if (answer < summ) {
		answer = summ;
	}
}
void pickk(int cnt, int idx) {
	if (cnt == 3) {
		killEnem();
		return;
	}

	for (int i = idx; i < M; i++) {
		arch[cnt] = i;
		pickk(cnt + 1, i + 1);
	}
}
void init() {
	ios::sync_with_stdio(false);
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &enemy[i][j]);
		}
	}
}
int main() {
	init();
	pickk(0,0);
	printf("%d\n", answer);
}