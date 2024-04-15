/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>

#define MOD 1000000007
#define MAX_N 501

using namespace std;
using ll = long long;
const ll INF = (1ll << 55);

ll adj[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M, Q;
	cin >> N >> M >> Q;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			adj[i][j] = INF;
		adj[i][i] = 0;
	}
	
	for(int i = 0; i < M ; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		if(c < adj[a][b]) {
			adj[a][b] = c;
			adj[b][a] = c;
		}
	}
	
	for(int k = 0; k < N; k++) 
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					adj[j][i] = adj[i][j];
				}
	
	for(int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(adj[a][b] >= INF)
			cout << -1 << '\n';
		else 
			cout << adj[a][b] << '\n';
	}
}