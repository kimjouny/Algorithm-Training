#include <iostream>
#include <queue>
#define MAX 500001
using namespace std;

int N, K;
int subin[2][MAX];
int getSister(int cur, int time) {
	if (cur >= MAX)return -1;
	if (subin[time % 2][cur] != -1 && subin[time % 2][cur] <= time)return time;
	return getSister(cur+time+1, time + 1);
}
void init() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < MAX; j++) {
			subin[i][j] = -1;
		}
	}
}
void getSubin(int n) {
	init();
	queue<pair<int, int>> q;
	q.push(make_pair(0, n));
	subin[0][n] = 0;

	while (!q.empty()) {
		int tim = q.front().first;
		int pos = q.front().second;
		q.pop();

		if (pos + 1 < MAX&&subin[(tim + 1) % 2][pos + 1] == -1) {
			q.push(make_pair(tim + 1, pos + 1));
			subin[(tim + 1) % 2][pos + 1] = tim + 1;
		}

		if (pos * 2 < MAX&&subin[(tim + 1) % 2][pos * 2] == -1) {
			q.push(make_pair(tim + 1, pos * 2));
			subin[(tim + 1) % 2][pos * 2] = tim + 1;
		}

		if (pos - 1 >= 0 && subin[(tim + 1) % 2][pos - 1] == -1) {
			q.push(make_pair(tim + 1, pos - 1));
			subin[(tim + 1) % 2][pos - 1] = tim + 1;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	getSubin(N);
	printf("%d\n",getSister(K, 0));
}