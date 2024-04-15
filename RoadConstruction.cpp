#include <iostream>

using namespace std;

int par[100001]; // parent of each group
int sz[100001]; // size of each group

// return topmost parent of this node
// compress the tree during this operation as well
int find(int x) {
	if(par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

// return true if merge was successful
// return false if merge was unsuccessful
bool merge(int a, int b) {
	int pA = find(a);
	int pB = find(b);
	// they have the same parent
	if(pA == pB) 
		return false;
	if(sz[pA] < sz[pB]) { // merge A's group into B's group
		par[pA] = pB;
		sz[pB] += sz[pA];
	} else { // merge B's group into A's group
		par[pB] = pA;
		sz[pA] += sz[pB];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	// initialize parent and size arrays
	// each node initially points to itself
	for(int i = 1; i <= N; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	
	int numComponents = N;
	int maxSize = 1;
	for(int day = 0; day < M; day++) {
		int a, b; // create road between city a and b
		cin >> a >> b;
		if(merge(a, b))
			numComponents--;
		maxSize = max(maxSize, sz[find(a)]);
		cout << numComponents << ' ' << maxSize << '\n';
	}
}