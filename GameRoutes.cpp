#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[100001];
int in[100001] = {0}, way[100001] = {0};

int main() {
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!in[i])
			q.push(i);
	way[1] = 1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int c: adj[x]) {
			in[c]--;
			way[c] = (way[c]+way[x])%1000000007;
			if(!in[c]) {
				q.push(c);
			}
		}
	}
	cout << way[n] << '\n';
	return 0;
}