#include <iostream>

using namespace std;

int N,M;
int land[10001];
int estate() {
	int avail = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N;i++) {
		scanf("%d", &land[i]);
	}
	
	for (int i = 0; i < N; i) {
		bool isM = false;
		int summ = 0;
		int idx = i;
		while (summ<M&&idx<N) {
			summ += land[idx];
			idx++;
		}
		if (summ == M)avail++;
		i++;
	}
	return avail;
}
int main() {
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d %d\n", t, estate());
	}
	return 0;
}