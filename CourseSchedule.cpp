#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int in[100001] = {0};
int q[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	int sz = 0;
	for(int i = 1; i <= n; i++)
		if(!in[i])
			q[sz++] = i;
	for(int idx = 0; idx < sz; idx++) {
		for(int c: adj[q[idx]]) {
			in[c]--;
			if(!in[c])
				q[sz++] = c;
		}
	}
	if(sz != n) 
		cout << "IMPOSSIBLE\n";
	else {
		for(int i = 0; i < sz; i++)
			cout << q[i] << ' ';
		cout << '\n';
	}
	return 0;
}