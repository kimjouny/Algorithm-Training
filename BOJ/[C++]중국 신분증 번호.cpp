#include <iostream>
#define YOON(y)  (((y)%4==0)-((y)%100==0)+((y)%400==0)) 

using namespace std;

int region, yyyy, mm, dd, order;
int pnum;
bool isMan = true;
long long checksum;
int days[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

void addChecksum(int scale, int param) {
	for (int i = scale; i >= 1; i /= 10) {
		checksum += param / i*pnum;
		param %= i;
		pnum = (pnum >> 1);
	}
}
bool CHECK() {
	if (order == 0)return false;
	if (order % 2 == 0) isMan = false;
	pnum = (1 << 17);

	addChecksum(100000, region);
	addChecksum(1000, yyyy);
	addChecksum(10, mm);
	addChecksum(10, dd);
	addChecksum(100, order);

	if (checksum % 11 != 1)return false;
	return true;
}
bool YYYYMMDD() {
	if (yyyy < 1900 || yyyy>2011)return false;
	if (mm < 1 || mm>12)return false;
	if (mm == 2) { if (YOON(yyyy)) { days[2] += 1; } }
	if (dd < 1 || dd > days[mm]) return false;
	return true;
}
bool searchRegion() {
	bool finded = false;
	int N;
	scanf("%d", &N);
	int regcode;
	for (int i = 0; i < N; i++) {
		scanf("%d", &regcode);
		if (regcode == region)finded = true;
	}
	if (finded)return true;
	else return false;
}
void enterID() {
	scanf("%6d", &region);
	scanf("%4d", &yyyy);
	scanf("%2d", &mm);
	scanf("%2d", &dd);
	scanf("%3d", &order);
	char ch;
	scanf("%c", &ch);
	if (ch == 'X') {
		checksum = 10;
	}
	else {
		checksum = ch - '0';
	}
}
int main() {
	enterID();
	if (searchRegion()) {
		if (YYYYMMDD()) { 
			if (CHECK()) {
				if (isMan) printf("M\n");
				else printf("F\n");
				return 0;
			}
		 }
	}
	printf("I\n");
	return 0;
}