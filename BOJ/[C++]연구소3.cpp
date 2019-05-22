#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;// N : �������� ũ�� , M: ���� �� �ִ� ���̷����� ����
char maps[51][51];//�������� �ִ� ũ�� 50
char reps[51][51];
int visit[51][51];
int mixvir[11];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int answer = 30000;
vector<pair<int,int>> virs;
void goSpread() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
			reps[i][j] = maps[i][j];
		}
	}
	queue < pair<int, int> > q;

	for (int i = 0; i < M; i++) {
		q.push(make_pair(virs[mixvir[i]].first, virs[mixvir[i]].second));
		visit[virs[mixvir[i]].first][virs[mixvir[i]].second] = 1;
	}

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny>=0&&ny<N&&nx>=0&&nx<N) {
				if (reps[ny][nx] == '0'&&visit[ny][nx]==0) { 
					q.push(make_pair(ny, nx));
					reps[ny][nx] = '*';
					visit[ny][nx] = visit[yy][xx] + 1;
				}
				else if (reps[ny][nx] == '*'&&visit[ny][nx] == 0) { // ��Ȱ�� ���̷��� ó��
					reps[ny][nx] = 'v';
					q.push(make_pair(ny, nx));
					visit[ny][nx] = visit[yy][xx] + 1;
				}
			}
		}
	}
	int maxnum = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (reps[i][j] == '0') return; // ���̷����� Ȯ�� ���� ��,
			if (reps[i][j] == 'v')continue; // ��Ȱ�� ���̷��� �ڵ鸵
			if (maxnum < visit[i][j]) {
				
				maxnum = visit[i][j];
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	if (maxnum - 1 < answer)answer = maxnum - 1;
}
void selectActive(int cnt, int idx) { // ���� ���
	if (cnt == M) {
		goSpread();
		return;
	}
	for (int i = idx; i < virs.size(); i++) {
		mixvir[cnt] = i;
		selectActive(cnt + 1, i + 1);
	}
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == '1') { // ���ϰ�� - �� �ٲ㼭 �����մϴ�.
				maps[i][j] = '-';
			}
			else if (maps[i][j] == '2') { // �����̴� ��ġ ������ �迭�� ����ϴ�.
				virs.push_back(make_pair(i, j));
				maps[i][j] = '*';
			}
		}
	}
}

int main() {
	init();
	selectActive(0,0);
	if (answer == 30000) {
		cout << -1 << endl;
	}
	else {
		cout << answer << endl;
	}
	return 0;
}