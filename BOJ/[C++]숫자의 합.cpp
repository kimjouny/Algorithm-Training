#include <iostream>

using namespace std;
int N;
int answer;
void init() {
	scanf("%d", &N);
	getchar();
	while (N--) {
		char temp;
		scanf("%c", &temp);
		answer += (int)(temp - '0');
	}
}
int main() {
	init();
	printf("%d\n", answer);
	return 0;
}