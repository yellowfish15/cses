#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj[100001];
bool vis[100001] = {false};
int depth[100001] = {0};
int par[100001] = {0};

void dfs(int node, int p, int d) {
	par[node] = p;
	depth[node] = d;
	vis[node] = true;
	
	for(int c: adj[node]) {
		if(!vis[c])
			dfs(c, node, d+1);
		else if(depth[c] && depth[node]-depth[c] >= 1) {
			stack<int> s;
			s.push(c);
			s.push(node);
			while(s.top() != c)
				s.push(par[s.top()]);
			cout << s.size() << '\n';
			while(!s.empty()) {
				cout << s.top() << ' ';
				s.pop();
			}
			cout << '\n';
			exit(0);
		}
	}
	par[node] = 0;
	depth[node] = 0;
}

int main() {
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs(i, 0, 1);
	cout << "IMPOSSIBLE\n";
	return 0;
}