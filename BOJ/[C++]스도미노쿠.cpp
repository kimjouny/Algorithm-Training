#include <iostream>

using namespace std;
int N;
int d[10][10];
bool combi[10][10];
bool grid[10][3][3];
bool rows[10][10];
bool cols[10][10];
bool isfind;
int nums[2];


void ps() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d", d[i][j]);
		}
		printf("\n");
	}
}
void DFS(int r, int c) {
	
	
	if (isfind)return;

	if (r == 9 && c == 10) { 
		isfind = true;
		ps();
		return; 
	} 

	if (c == 10) {
		int summ = 0;
		for (int i = 1; i <= 9; i++)summ += d[r][i];
		if (summ == 45) { r += 1; c = 1; }
		else return;
	}

	if (d[r][c] != 0) { DFS(r, c + 1); return; }

	for (int i = 1; i <= 8; i++) {
		for (int j = i+1; j <= 9; j++) {
			
			//verti
			if (c + 1 <= 9) {
				if (!rows[r][i] && !rows[r][j]) {
					if (d[r][c] == 0 && d[r][c + 1] == 0 && !combi[i][j] && !combi[j][i]) {
						//12
						if (!grid[i][(r - 1) / 3][(c - 1) / 3] && !grid[j][(r - 1) / 3][c / 3] && !cols[c][i] && !cols[c + 1][j]) {
							d[r][c] = i;
							d[r][c + 1] = j;
							combi[i][j] = true;
							combi[j][i] = true;
							rows[r][i] = true;
							rows[r][j] = true;
							cols[c][i] = true;
							cols[c + 1][j] = true;
							grid[i][(r - 1) / 3][(c - 1) / 3] = true;
							grid[j][(r - 1) / 3][c / 3] = true;
							DFS(r, c + 2); 
							d[r][c] = 0;
							d[r][c + 1] = 0;
							combi[i][j] = false;
							combi[j][i] = false;
							grid[i][(r - 1) / 3][(c - 1) / 3] = false;
							grid[j][(r - 1) / 3][c / 3] = false;
							rows[r][i] = false;
							rows[r][j] = false;
							cols[c][i] = false;
							cols[c + 1][j] = false;
						}
						//21
						if (!grid[j][(r - 1) / 3][(c - 1) / 3] && !grid[i][(r - 1) / 3][c / 3] && !cols[c][j] && !cols[c + 1][i]) {
							d[r][c] = j;
							d[r][c + 1] = i;
							combi[i][j] = true;
							combi[j][i] = true;
							grid[j][(r - 1) / 3][(c - 1) / 3] = true;
							grid[i][(r - 1) / 3][c / 3] = true;
							rows[r][i] = true;
							rows[r][j] = true;
							cols[c][j] = true;
							cols[c + 1][i] = true;
							DFS(r, c + 2);
							d[r][c] = 0;
							d[r][c + 1] = 0;
							combi[i][j] = false;
							combi[j][i] = false;
							grid[j][(r - 1) / 3][(c - 1) / 3] = false;
							grid[i][(r - 1) / 3][c / 3] = false;
							rows[r][i] = false;
							rows[r][j] = false;
							cols[c][j] = false;
							cols[c + 1][i] = false;
						}
					}
				}
				
			}
			//hori
			
			if (r + 1 <= 9) {
				if (!cols[c][i] && !cols[c][j]) {
					if (d[r][c] == 0 && d[r + 1][c] == 0 && !combi[i][j] && !combi[j][i]) {
						//12
						if (!grid[i][(r - 1) / 3][(c - 1) / 3] && !grid[j][r / 3][(c - 1) / 3]&&!rows[r][i]&&!rows[r+1][j]) {
							d[r][c] = i;
							d[r + 1][c] = j;
							combi[i][j] = true;
							combi[j][i] = true;
							grid[i][(r - 1) / 3][(c - 1) / 3] = true;
							grid[j][r / 3][(c - 1) / 3] = true;
							rows[r][i] = true;
							rows[r + 1][j] = true;
							cols[c][i] = true;
							cols[c][j] = true;
							DFS(r, c + 1);
							d[r][c] = 0;
							d[r + 1][c] = 0;
							combi[i][j] = false;
							combi[j][i] = false;
							grid[i][(r - 1) / 3][(c - 1) / 3] = false;
							grid[j][r / 3][(c - 1) / 3] = false;
							rows[r][i] = false;
							rows[r + 1][j] = false;
							cols[c][i] = false;
							cols[c][j] = false;
						}
						//21
						if (!grid[j][(r - 1) / 3][(c - 1) / 3] && !grid[i][r / 3][(c - 1) / 3] && !rows[r][j] && !rows[r + 1][i]) {
							d[r][c] = j;
							d[r + 1][c] = i;
							combi[i][j] = true;
							combi[j][i] = true;
							grid[j][(r - 1) / 3][(c - 1) / 3] = true;
							grid[i][r / 3][(c - 1) / 3] = true;
							rows[r][j] = true;
							rows[r + 1][i] = true;
							cols[c][i] = true;
							cols[c][j] = true;
							DFS(r, c + 1);
							d[r][c] = 0;
							d[r + 1][c] = 0;
							combi[i][j] = false;
							combi[j][i] = false;
							grid[j][(r - 1) / 3][(c - 1) / 3] = false;
							grid[i][r / 3][(c - 1) / 3] = false;
							rows[r][j] = false;
							rows[r + 1][i] = false;
							cols[c][i] = false;
							cols[c][j] = false;
						}
					}
				}
				
			}
		}
	}

}
void init() {
	ios::sync_with_stdio(false);
	int round = 1;
	while (1) {
		scanf("%d", &N);
		if (N == 0)return;

		isfind = false;
		for (int i = 1; i <=9; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					grid[i][j][k] = false;
				}
			}
			for (int j = 1; j <= 9; j++) {
				d[i][j] = 0;
				combi[i][j] = false;
				rows[i][j] = false;
				cols[i][j] = false;
			}
		}
		for (int i = 1; i <= 9; i++)combi[i][i] = true;

		char yinp;
		int xinp;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				scanf("%d", &nums[j]);
				getchar();
				scanf("%1c", &yinp);
				yinp = yinp - 'A' + 1;
				scanf("%d", &xinp);
				d[yinp][xinp] = nums[j];
				grid[nums[j]][(yinp - 1) / 3][(xinp - 1) / 3] = true;
				rows[yinp][nums[j]] = true;
				cols[xinp][nums[j]] = true;

			}
			combi[nums[0]][nums[1]] = true;
			combi[nums[1]][nums[0]] = true;
		}

		for (int j = 1; j <= 9; j++) {
			getchar();
			scanf("%1c", &yinp);
			yinp = yinp - 'A' + 1;
			scanf("%d", &xinp);
			d[yinp][xinp] = j;
			grid[j][(yinp - 1) / 3][(xinp - 1) / 3] = true;
			rows[yinp][j] = true;
			cols[xinp][j] = true;
		}
		printf("Puzzle %d\n", round);
		DFS(1, 1);
		round++;
	}
}
int main() {
	init();
	return 0;
}