#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;// N : 연구소의 크기 , M: 놓을 수 있는 바이러스의 갯수
char maps[51][51];//연구소의 최대 크기 50
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
				else if (reps[ny][nx] == '*'&&visit[ny][nx] == 0) { // 비활성 바이러스 처리
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
			if (reps[i][j] == '0') return; // 바이러스가 확산 실패 시,
			if (reps[i][j] == 'v')continue; // 비활성 바이러스 핸들링
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
void selectActive(int cnt, int idx) { // 조합 모듈
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
			if (maps[i][j] == '1') { // 벽일결우 - 로 바꿔서 저장합니다.
				maps[i][j] = '-';
			}
			else if (maps[i][j] == '2') { // 곰팡이는 위치 정보를 배열에 담습니다.
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