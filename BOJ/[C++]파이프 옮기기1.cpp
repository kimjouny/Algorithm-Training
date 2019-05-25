#include<iostream>

using namespace std;

int N;
bool maps[17][17];
int types = 0;

bool isIn(int yy, int xx) {
	if (yy >= 0 && yy < N&&xx >= 0 && xx < N)return true;
	
	return false;
}

bool goDiagonal(int yy, int xx) {
	if (isIn(yy + 1, xx + 1)) {
		if (!maps[yy + 1][xx + 1] && !maps[yy + 1][xx] && !maps[yy][xx + 1])return true;
	}	
	return false;
}
bool goVerti(int yy, int xx) {
	if (isIn(yy + 1, xx)) {
		if (!maps[yy + 1][xx])return true;
	}
	return false;
}
bool goHori(int yy, int xx) {
	if (isIn(yy, xx + 1)) {
		if (!maps[yy][xx + 1])return true;
	}
	return false;
}
void DFS(int yy,int xx,int kind) {
	if (yy == N - 1 && xx == N - 1) {
		types += 1;
		return;
	}

	if (kind == 0) {
		if (goDiagonal(yy, xx)) {
			DFS(yy + 1, xx + 1,1);
		}
		if (goHori(yy, xx)) {
			DFS(yy, xx + 1, 0);
		}
	}
	else if (kind == 1) {
		if (goVerti(yy, xx)) {
			DFS(yy + 1, xx, 2);
		}
		if (goHori(yy, xx)) {
			DFS(yy, xx + 1, 0);
		}
		if (goDiagonal(yy, xx)) {
			DFS(yy + 1, xx + 1, 1);
		}
	}
	else if (kind == 2) {
		if (goDiagonal(yy, xx)) {
			DFS(yy + 1, xx + 1, 1);
		}
		if (goVerti(yy, xx)) {
			DFS(yy+1, xx, 2);
		}
	}
}
void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
}
int main() {
	init();
	DFS(0, 1, 0); // 초기 위치
	printf("%d\n", types);
	return 0;
}