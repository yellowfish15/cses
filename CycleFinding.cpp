/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>

#define MOD 1000000007
#define MAX_N 2500

using namespace std;
using ll = long long;
const ll INF = (1ll << 55);

ll dist[2505];
ll edges[5005][3];
ll par[MAX_N];

stack<ll> st;
unordered_set<ll> vis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		par[i] = -1; // initially no parent
		dist[i] = -1;
	}
	dist[0] = 0;
		
	for(int i = 0; i < M; i++)
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	
	for(int I = 0; I < N-1; I++) {
		for(int e = 0; e < M; e++) {
			if(dist[edges[e][1]] > dist[edges[e][0]] + edges[e][2]) {
				dist[edges[e][1]] = dist[edges[e][0]] + edges[e][2];
				par[edges[e][1]] = edges[e][0];
			}
		}
	}
	
	bool cycle = false;
	// detect negative cycle
	for(int e = 0; e < M; e++) {
		if(dist[edges[e][1]] > dist[edges[e][0]] + edges[e][2]) {
			par[edges[e][1]] = edges[e][0];
			// negative cycle found
			cycle = true;
			st.push(edges[e][1]);
			while(!vis.count(st.top())) {
				ll curr = st.top();
				vis.insert(curr);
				ll p = par[curr];
				st.push(p);
			}
			break;
		}
	}
	
	if(cycle) {
		cout << "YES" << '\n';
		ll start = st.top();
		st.pop();
		cout << start << ' ';
		while(st.top() != start) {
			cout << st.top() << ' ';
			st.pop();
		}
		cout << start << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
	
}