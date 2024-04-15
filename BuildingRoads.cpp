#include <iostream>
#include <vector>

using namespace std;

int par[100001];
int rk[100001];

// return parent of x
int find(int x) {
	if(par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

// merge two cities, a and b
void merge(int a, int b) {
	int pA = find(a); // find parent of a
	int pB = find(b); // find parent of b
	if(pA == pB) // these two nodes are already merged
		return;
	if(rk[pA] < rk[pB]) {
		par[pA] = pB;
		rk[pB]++;
	} else {
		par[pB] = par[pA];
		rk[pA]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	// initialize parent and rank arrays
	for(int i = 1; i <= N; i++) {
		par[i] = i;
		rk[i] = 1;
	}
	
	// merge all roads
	for(int road = 0; road < M; road++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	
	vector<int> v;
	// merge everything into city 1
	for(int city = 2; city <= N; city++) {
		int base = find(1); // base city
		int test = find(city);
		// merge
		if(base != test) {
			merge(1, city);
			v.push_back(city);
		}
	}
	
	cout << v.size() << '\n';
	for(int city: v)
		cout << 1 << ' ' << city << '\n';
	
}