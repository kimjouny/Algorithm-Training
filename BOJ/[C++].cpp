#include <iostream>

using namespace std;

int N;
int W[11];
bool deleted[9];
bool picked[9];
int permus[9];
int answer = -1;

int  energy() {
	int summ = 0;
	for (int i = 1; i <= N - 2; i++) {
		deleted[i] = false;
	}
	for (int i = 1; i <= N - 2; i++) {
		int idx = permus[i];
		deleted[idx] = true;
		int ll = idx - 1;
		int rr = idx + 1;
		while (deleted[ll]) {
			ll--;
		}
		while (deleted[rr]) {
			rr++;
		}
		summ += W[ll] * W[rr];
	}
	
	return summ;
}
void permutating(int cnt) {
	if (cnt == N - 1) {
		int charge = energy();
		answer = answer < charge ? charge : answer;
		return;
	}

	for (int i = 1; i <= N - 2; i++) {
		if (!picked[i]) {
			picked[i] = true;
			permus[i] = cnt;
			permutating(cnt + 1);
			picked[i] = false;
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
}
int main() {
	init();
	permutating(1);
	cout << answer << '\n';
	return 0;
}