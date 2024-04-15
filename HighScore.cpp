/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAX_N 100005

using namespace std;
using ll = long long;
const ll INF = (1ll << 57);
const ll NEG_INF = (-1ll << 57);

struct Edge {
	ll cost;
	int t;
};

ll dist[2505];
vector<Edge> adj[2505];

bool reachS[2505];
bool reach[2505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int a, b;
		ll cost;
		cin >> a >> b >> cost;
		adj[a].push_back({cost, b});
	}
	
	for(int i = 0; i <= N; i++) {
		dist[i] = NEG_INF;
		reach[i] = false;
		reachS[i] = false;
	}
	reachS[1] = true;
	reach[N] = true;
	dist[1] = 0;
	
	for(int I = 0; I < N-1; I++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < adj[i].size(); j++) {
				int t = adj[i][j].t;
				ll cost = adj[i][j].cost;
				if(dist[t] < dist[i] + cost) {
					dist[t] = dist[i] + cost;
				}
				reachS[t] = reachS[t] || reachS[i];
				reach[i] = reach[i] || reach[t]; // get reachable nodes
			}
		}
	}
		
	bool arbit = false;
	for(int I = 0; I < N-1 && !arbit; I++) {
		for(int i = 1; i <= N && !arbit; i++) {
			for(int j = 0; j < adj[i].size() && !arbit; j++) {
				int t = adj[i][j].t;
				ll cost = adj[i][j].cost;
				if(dist[t] < dist[i] + cost && reach[t] && reachS[t]) {
					arbit = true;
					break;
				}
			}
		}
	}
	
	if(N == 1 && adj[1][0].cost > 0)
		cout << -1;
	else if(!arbit)
		cout << dist[N] << '\n';
	else
		cout << -1;
}