#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int vis[200001] = {0};
int order[200001];
vector<vector<int>> adj(200001, vector<int>());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = -1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(x == n)
			break;
		for(int c: adj[x])
			if(!vis[c]) {
				q.push(c);
				vis[c] = x;
			}
	}
	
	if(!vis[n]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	int c = n;
	int pos = n;
	while(c != -1) {
		order[pos--] = c;
		c = vis[c];
	}
	cout << n-pos << '\n';
	for(pos++;pos <= n; pos++)
		cout << order[pos] << ' ';
	cout << '\n';
	
	
	return 0;
}