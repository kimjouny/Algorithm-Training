#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int router[100001];

struct NETWORK {
	int v1;
	int v2;
	int cost;
};
vector<NETWORK> v;

int mincost = 0;


int getParent(int vertex) {
	if (vertex == router[vertex]) {
		return vertex;
	}
	else {
		return getParent(router[vertex]);
	}
}

void hasCycle(NETWORK net) {
	int v1Parent = getParent(net.v1);
	int v2Parent = getParent(net.v2);
	if (v1Parent== v2Parent)return;

	if (v1Parent > v2Parent)router[v2Parent] = v1Parent;
	else router[v1Parent] = v2Parent;

	mincost += net.cost;
}
void KRU() {
	for (int i = 0; i < v.size(); i++) {
		hasCycle(v[i]);
	}
}

bool compare(NETWORK a, NETWORK b) {
	return a.cost < b.cost;
}


void init() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)router[i] = i;
	int temp;
	cin >> temp;
	for (int t = 1; t <= temp; t++) {
		NETWORK net;
		cin >> net.v1 >> net.v2 >> net.cost;
		v.push_back(net);
	}
	sort(v.begin(), v.end(), compare);
}

int main() {
	init();
	KRU();
	cout << mincost << '\n';
	return 0;
}
