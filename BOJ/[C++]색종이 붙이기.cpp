#include<iostream>
using namespace std;
int mm[11][11];
int used[6];
int answer = 99999;
bool isFull() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mm[i][j] == -1)return false;
		}
	}
	return true;
}
void defill(int id, int jd, int size) {
	for (int i = id; i < id + size; i++) {
		for (int j = jd; j < jd + size; j++) {
			mm[i][j] = -1;;
		}
	}
}
void fill(int id, int jd,int size) {
	for (int i = id; i < id + size; i++) {
		for (int j = jd; j < jd + size; j++) {
			mm[i][j] = size;
		}
	}
}
bool inBound(int id, int jd, int size) {
	if (id + size <= 10 && jd + size <= 10) {
		for (int i = id; i < id + size; i++) {
			for (int j = jd; j < jd + size; j++) {
				if (mm[i][j] != -1)return false;
			}
		}
		return true;
	}
	return false;
}
void DFS() {
	if (isFull()) {
		int summ = used[1] + used[2] + used[3] + used[4] + used[5];
		if (answer > summ)answer = summ;
		return;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mm[i][j] == -1){
				for (int k = 5; k > 0; k--) {
					if (inBound(i, j, k) && used[k]<5) {
						fill(i, j, k);
						used[k]++;
						DFS();
						defill(i, j, k);
						used[k]--;
					}
				}
				 return;
			}
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &mm[i][j]);
			if (mm[i][j] == 1) {
				mm[i][j] = -1;
			}
		}
	}
}
int main() {
	init();
	DFS();
	if (answer == 99999)answer = -1;
	printf("%d\n", answer);
}