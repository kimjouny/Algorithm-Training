#include <iostream>

using namespace std;

int N, M;
long long d[1000001];
long long mini = 0;
long long maxi = -1;
long long answer;
void parametric() {
	while (maxi >= mini) {

		long long mid = (maxi + mini) / 2;
		long long summ = 0;
		for (int i = 0; i < N; i++) {
			if (mid < d[i])summ += (d[i] - mid);
		}

		if (summ >= M) {
			answer = mid;
			mini = mid + 1;
		}
		else {
			maxi = mid - 1;
		}
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		if (d[i] > maxi)maxi = d[i];
	}
}
int main() {
	init();
	parametric();
	cout << answer << '\n';
	return 0;
}