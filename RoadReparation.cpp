#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct Road {
	int a, b;
	ll c;
	Road(int a, int b, ll c) : a(a), b(b), c(c) {}
};


int par[100001];
int rk[100001];
vector<Road> roads;

bool sorter(Road lhs, Road rhs) {
	return lhs.c < rhs.c;
}

int find(int x) {
	if(par[x] != x) 
		par[x] = find(par[x]);
	return par[x];
}

bool merge(int a, int b) {
	int pA = find(a);
	int pB = find(b);
	if(pA == pB)
		return false;
	if(rk[pA] < rk[pB]) {
		par[pA] = pB;
		rk[pB]++;
	} else {
		par[pB] = pA;
		rk[pA]++;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		par[i] = i;
		rk[i] = 1;
	}
	
	for(int i = 0; i < M; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		roads.push_back({a, b, c});
	}

	sort(roads.begin(), roads.end(), &sorter);
	
	ll total = 0;
	int cnt = N; // # of components initially
	for(Road r: roads) {
		if(merge(r.a, r.b)) {
			total += r.c;
			cnt--;
		}
	}
	
	if(cnt > 1)
		cout << "IMPOSSIBLE\n";
	else
		cout << total << '\n';
	
}