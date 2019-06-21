#include <iostream>

using namespace std;

int N, M;
char d[22][22];
int coins[2][2];
int answer = 777;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void DFS(int cnt, int dir) {
	if (cnt == 11)return;
	if (cnt >= answer)return;
	if (coins[0][0] == coins[1][0] && coins[0][1] == coins[1][1])return;

	if (d[coins[0][0]][coins[0][1]] == '!'&&d[coins[1][0]][coins[1][1]] == '!') {
		return;
	}
	else if (d[coins[0][0]][coins[0][1]] == '!'||d[coins[1][0]][coins[1][1]] == '!') {
		answer = answer > cnt ? cnt : answer;
		return;
	}

	for (int i = 0; i < 4; i++) {
		bool dd[2];
		for (int j = 0; j < 2; j++) {
			if (d[coins[j][0] + dy[i]][coins[j][1] + dx[i]] == '#') {
				dd[j] = true;
			}
			else {
				dd[j] = false;
				coins[j][0] += dy[i];
				coins[j][1] += dx[i];
			}
		}
		DFS(cnt + 1, i);
		for (int j = 0; j < 2; j++) {
			if (!dd[j]) {
				coins[j][0] -= dy[i];
				coins[j][1] -= dx[i];
			}
		}
	}
}
void init() {
    scanf("%d %d", &N, &M);
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++)d[i][j] = '!';
	}
	int cidx = 0;
	for (int i = 1; i <= N; i++) {
		getchar();
		for (int j = 1; j <= M; j++) {
			scanf("%c", &d[i][j]);
			if (d[i][j] == 'o') {
				coins[cidx][0] = i;
				coins[cidx][1] = j;
				d[i][j] = '.';
				cidx++;
			}
		}
	}
}
int main() {
	init();
	DFS(0,-1);
	if (answer == 777)answer = -1;
	printf("%d\n", answer);
	return 0;
}