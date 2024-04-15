#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
struct Edge {
	int b; ll c;
	
	bool operator <(const Edge& rhs) const {
		return c > rhs.c;
	}
};

vector<Edge> adj[100001];
int vis[100001] = {0}; // # of visits

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b; ll c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	
	priority_queue<Edge> pq;
	pq.push({1, 0});
	while(!pq.empty()) {
		Edge s = pq.top();
		pq.pop();
		if(vis[s.b] >= k)
			continue;
		vis[s.b]++;
		if(s.b == n)
			cout << s.c << ' ';
		for(Edge e: adj[s.b])
			if(vis[e.b] < k)
				pq.push({e.b, s.c+e.c});
	}
	cout << '\n';
	
	return 0;
}