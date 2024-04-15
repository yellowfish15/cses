#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
vector<int> adj[200001];
int dp[200001][2]; // 0 = without connecting, 1 = with connecting
 
void dfs(int curr, int par) {
	dp[curr][0] = dp[curr][1] = 0;
	for(int child: adj[curr]) {
		if(child != par) {
			dfs(child, curr);
			dp[curr][0] += max(dp[child][0], dp[child][1]);
		}
	}
	
	for(int child: adj[curr])
		if(child != par) 
			dp[curr][1] = max(dp[curr][1], dp[curr][0]-max(dp[child][0], dp[child][1])+dp[child][0]+1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, -1);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}