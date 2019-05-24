#include <iostream>
using namespace std;
#define MAXNUM 4746794007248502785;
int N;
char ops[11];
long long ands[11];
long long reps[11];
long long maxi = -4476578029606273025;
bool getpri[11];

int flv(int oidx) {
	if (reps[oidx] != MAXNUM) {
		return oidx;
	}
	while(reps[oidx] == MAXNUM){
		oidx--;
	}
	return oidx;
}

int frv(int oidx) {
	if (reps[oidx] != MAXNUM) {
		return oidx;
	}
	while (reps[oidx] == MAXNUM) {
		oidx++;
	}
	return oidx;
}
void calc() {

	for (int i = 0; i < N / 2+1; i++) {
		reps[i] = ands[i];
	}
	for (int i = 0; i < N / 2; i++) {
		if (getpri[i]) {
			int ld = flv(i);
			int rd = frv(i+1);
			if (ops[i] == '+') {
				reps[ld] = reps[ld] + reps[rd];
				reps[rd]= MAXNUM;
			}
			else if(ops[i] == '-'){
				reps[ld] = reps[ld] - reps[rd];
				reps[rd] = MAXNUM;
			}
			else if (ops[i] == '*') {
				reps[ld] = reps[ld] * reps[rd];
				reps[rd] = MAXNUM;
			}
		}
	}

	for (int i = 0; i < N / 2; i++) {
		if (!getpri[i]) {
			int ld = flv(i);
			int rd = frv(i + 1);
			if (ops[i] == '+') {
				reps[ld] = reps[ld] + reps[rd];
				reps[rd] = MAXNUM;
			}
			else if(ops[i] == '-'){
				reps[ld] = reps[ld] - reps[rd];
				reps[rd] = MAXNUM;
			}
			else if (ops[i] == '*') {
				reps[ld] = reps[ld] * reps[rd];
				reps[rd] = MAXNUM;
			}
		}
	}
	
	if (maxi < reps[0]) {
		maxi = reps[0];
	}
}

void mixx(int cnt) {
	if (cnt == N/2) {
		calc();
		return;
	}

	if (cnt == 0 || !getpri[cnt - 1]) {
		getpri[cnt] = true;
		mixx(cnt + 1);
	}
	getpri[cnt] = false;
	mixx(cnt + 1);
}

void init() {
	cin >> N;
	getchar();
	for (int i = 0; i < N/2; i++) {
		scanf("%1d", &ands[i]);
		scanf("%1c", &ops[i]);
	}
	scanf("%1lld", &ands[N/2]);
}

int main() {
	init();
	mixx(0);
	printf("%lld\n", maxi);
}