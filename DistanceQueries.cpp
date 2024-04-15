// porkchops

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define LOG 20
vector<int> adj[200001]; // adjacency list
int sp[400002][LOG]; // sparse table
int log_2[400002];

vector<int> euler;
vector<int> depth;
int h[200001]; // first occurrence of i in euler tour

void dfs(int par, int curr, int d) {
	euler.push_back(curr);
	depth.push_back(d);
	h[curr] = euler.size()-1;
	for(int child: adj[curr]) {
		if(child != par) {
			dfs(curr, child, d+1);
			euler.push_back(curr);
			depth.push_back(d);
		}
	}
}

// precomputations
void comp() {
	log_2[0] = log_2[1] = sp[0][0] = 0;
	int pow = 2;
	for(int i = 1; i < euler.size(); i++) {
		sp[i][0] = i; // precompute sparse table
		// precompute log_2s
		log_2[i] = log_2[i-1];
		if(i == pow) {
			log_2[i]++;
			pow <<= 1;
		}
	}
	for(int j = 1, k = 1; j <= euler.size(); j<<=1, k++)
		for(int i = 0; (i+j) < euler.size(); i++) {
			// take index with minimum depth
			if(depth[sp[i][k-1]] < depth[sp[i+j][k-1]])
				sp[i][k] = sp[i][k-1];
			else
				sp[i][k] = sp[i+j][k-1];
		}
}


// query distance between node a and node b
int query(int a, int b) {
	if(a == b)
		return 0;
	a = h[a]; // first occurrence of a in euler tour
	b = h[b]; // first occurrence of b in euler tour
	
	// swap a and b if a > b
	if(a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	
	int size = b-a+1;
	int log = log_2[size];
	int i = sp[a][log];
	int j = sp[b-(1<<log)+1][log];
	int low = min(depth[i], depth[j]);
	
	return (depth[a]-low)+(depth[b]-low);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(-1, 1, 0); // dfs to find depths and generate euler tour
	comp(); // precompute
	
	for(int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}