#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int team[100001] = {0};
vector<vector<int>> adj(100001, vector<int>());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++) {
		if(team[i] != 0)
			continue;
		queue<int> q;
		q.push(i);
		team[i] = 1;
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for(int c: adj[x]) {
				if(team[c] == 0) {
					team[c] = team[x] == 1 ? 2 : 1;
					q.push(c);
				} else if(team[c] == team[x]) {
					cout << "IMPOSSIBLE\n";
					return 0;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		cout << team[i] << ' ';
	cout << '\n';
	return 0;
}