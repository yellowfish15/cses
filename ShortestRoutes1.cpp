/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MOD 1000000007
#define MAX_N 100000

using namespace std;
using ll = long long;
const ll INF = (1ll << 55);

ll dist[100005];

struct State {
	int b;
	ll dist;
	State(int b, ll dist) : b(b), dist(dist){};
	bool operator < (const State& oth) const { return dist > oth.dist;}
};

vector <State> adj[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		dist[i] = INF; // set all initial distances to infinity
	}
	
	for(int i = 0; i < M; i++) {
		int a, b;
		ll dist;
		cin >> a >> b >> dist;
		a--;
		b--;
		adj[a].push_back({b, dist});
	}
	
	priority_queue<State> q;
	q.push({0, 0L});
	while(!q.empty()) {
		State curr = q.top();
		q.pop();
		if(dist[curr.b] <= curr.dist) 
			continue;
		dist[curr.b] = curr.dist;
		for(State child: adj[curr.b]) {
			if(dist[child.b] == INF) {
				q.push({child.b, curr.dist + child.dist});
			}
		}
	}
	for(int i = 0; i < N; i++)
		cout << dist[i] << ' ';
	cout << '\n';
	
}