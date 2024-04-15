#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = (1ll << 58);
struct State {
	int node; ll cost; bool used;
	bool operator<(const State& rhs) const {
        return cost > rhs.cost;
    }
};

struct Edge {
	int b; ll c;
};

vector<Edge> adj[100001];
ll vis[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		ll c; int a, b; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	for(int i = 1; i <= n; i++)
		vis[i][0] = vis[i][1] = INF;
	priority_queue<State> pq;
	pq.push({1, 0, 0});
	while(!pq.empty()) {
		State s = pq.top(); pq.pop();
		if(vis[s.node][s.used] != INF)
			continue;
		vis[s.node][s.used] = s.cost;
		if(s.node == n && s.used) {
			cout << s.cost << '\n';
			break;
		}
		for(Edge e: adj[s.node]) {
			if(vis[e.b][s.used] == INF)
				pq.push({e.b, s.cost + e.c, s.used});
			if(!s.used) // we have not used discount
				if(vis[e.b][1] == INF)
					pq.push({e.b, s.cost + (e.c>>1), true});
		}
	}
	return 0;
}