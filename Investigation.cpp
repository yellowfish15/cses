#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
#define N 100001
const ll INF = (1ll << 58);
ll cost[N];
int numpaths[N], minflights[N], maxflights[N];

struct State {
	int curr; ll cost;
	
	bool operator<(const State& oth) const {
		return cost > oth.cost;
	}
};

vector<State> adj[N]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	
	cost[1] = minflights[1] = maxflights[1] = 0;
	numpaths[1] = 1;
	for(int i = 2; i <= n; i++) {
		cost[i] = INF;
		numpaths[i] = 0;
		minflights[i] = n<<1;
		maxflights[i] = 0;
	}
	
	for(int i = 0; i < m; i++) {
		int a,b; ll c; cin >> a >> b >> c; 
		adj[a].push_back({b, c});
	}
	
	priority_queue<State> q;
	q.push({1, 0});
	while(!q.empty()) {
		State s = q.top(); q.pop();
		if(s.curr == n)
			break;
		if(s.cost > cost[s.curr])
			continue;
		for(State c: adj[s.curr]) {
			ll sum = s.cost + c.cost;
			if(sum < cost[c.curr]) {
				cost[c.curr] = sum;
				numpaths[c.curr] = numpaths[s.curr];
				minflights[c.curr] = minflights[s.curr]+1;
				maxflights[c.curr] = maxflights[s.curr]+1;
				q.push({c.curr, s.cost+c.cost});
			} else if(sum == cost[c.curr]) {
				numpaths[c.curr] = (numpaths[c.curr]+numpaths[s.curr])%1000000007;
				minflights[c.curr] = min(minflights[c.curr], minflights[s.curr]+1);
				maxflights[c.curr] = max(maxflights[c.curr], maxflights[s.curr]+1);
			}
		}
	}
	
	cout << cost[n] << ' ' << numpaths[n] << ' ' << minflights[n] << ' ' << maxflights[n] << '\n';
	return 0;
}