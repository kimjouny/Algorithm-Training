#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int stars[12];
bool used[13];
vector<int> v;
vector<int> notused;
void magicStar() {
	printf("....%c....\n",(char)(stars[0]+'A'-1));
	printf(".%c.%c.%c.%c.\n", (char)(stars[1] + 'A' - 1), (char)(stars[2] + 'A' - 1), (char)(stars[3] + 'A' - 1), (char)(stars[4] + 'A' - 1));
	printf("..%c...%c..\n", (char)(stars[5] + 'A' - 1), (char)(stars[6] + 'A' - 1));
	printf(".%c.%c.%c.%c.\n", (char)(stars[7] + 'A' - 1), (char)(stars[8] + 'A' - 1), (char)(stars[9] + 'A' - 1), (char)(stars[10] + 'A' - 1));
	printf("....%c....\n", (char)(stars[11] + 'A' - 1));
}
bool r1Left() {
	if (stars[0] + stars[2] + stars[5] + stars[7] == 26)return true;
	return false;
}
bool r1Right() {
	if (stars[0] + stars[3] + stars[6] + stars[10] == 26)return true;
	return false;
}
bool r2() {
	if (stars[1] + stars[2] + stars[3] + stars[4] == 26)return true;
	return false;
}
bool r4() {
	if (stars[7] + stars[8] + stars[9] + stars[10] == 26)return true;
	return false;
}
bool r5Left() {
	if (stars[11] + stars[8] + stars[5] + stars[1] == 26)return true;
	return false;
}
bool r5Right() {
	if (stars[11] + stars[9] + stars[6] + stars[4] == 26)return true;
	return false;
}
bool calc() {
	if (!r1Left())return false;
	if (!r1Right())return false;
	if (!r2())return false;
	if (!r4())return false;
	if (!r5Left())return false;
	if (!r5Right())return false;

	return true;
}
void mixx() {
	sort(notused.begin(), notused.end());
	while (next_permutation(notused.begin(), notused.end())) {
		for (int i = 0; i < notused.size(); i++) {
			stars[v[i]] = notused[i];
		}
		if (calc())return;
	}
	
}
void defNotUsed() {
	for (int i = 1; i <= 12; i++) {
		if (!used[i])notused.push_back(i);
	}
}
void init() {
	ios::sync_with_stdio(false);
	char temp;
	int idx = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%c", &temp);
			if (temp == 'x') {
				v.push_back(idx);
				stars[idx++] = -1;
			}
			else if(temp>='A'&&temp<='Z'){
				stars[idx] = (int)(temp - 'A') + 1;
				used[stars[idx]] = true;
				idx++;
			}
		}
		getchar();
	}
}
int main() {
	init();
	defNotUsed();
	mixx();
	magicStar();
	return 0;
}