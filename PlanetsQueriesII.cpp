#include <iostream>
#include <queue>

using namespace std;

int sp[200001][20], deg[200001], id[200001][2];

void bfs(int x) {
	queue<int> q;
	id[x][0] = 1;
	q.push(x);
	while(!q.empty()) {
		int c = q.front(); q.pop();
		int cid = id[c][1]==0?id[c][0]:id[c][1];
		int child = sp[c][0];
		if(id[child][0] != 0) { // already been tagged once
			if(id[child][1] == 0) { // but not twice
				id[child][1] = cid+1;
				q.push(child);
			}
		} else { // not tagged before
			id[child][0] = cid+1;
			q.push(child);
		}
	}
}

int main() {
	int n,q; cin >> n >> q;
	
	// reset arrays
	for(int i = 0; i <= n; i++)
		deg[i] = id[i][0] = id[i][1] = 0;
	
	for(int i = 1; i <= n; i++) {
		cin >> sp[i][0];
		deg[sp[i][0]]++;
	}
	
	for(int i = 1; i <= n; i++)
		if(deg[i] == 0)
			bfs(i);
	
	for(int i = 1; i <= n; i++)
		if(id[i][0] == 0)
			bfs(i);
	
	for(int j = 1; j < 20; j++)
		for(int i = 1; i <= n; i++)
			sp[i][j] = sp[sp[i][j-1]][j-1];
	
	for(; q > 0; q--) {
		int a,b; cin>>a>>b;
		
		int tar = id[b][0];
		if(tar < id[a][0]) tar = id[b][1];
		if(tar < id[a][0]) {
			cout << -1 << '\n';
			continue;
		}
		tar -= id[a][0];
		for(int j = 1, k = 0; j <= tar; j <<= 1, k++)
			if(j&tar)
				a = sp[a][k];
		if(a == b) 
			cout << tar << '\n';
		else 
			cout << -1 << '\n';
		
	}
	
	return 0;
}