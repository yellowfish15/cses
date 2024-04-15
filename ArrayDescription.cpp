#include <iostream>

using namespace std;

int dp[100][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int x; cin >> x;
	for(int i = 0; i < 100; i++) {
		if(x == 0 || i == x-1)
			dp[i][0] = 1;
		else
			dp[i][0] = 0;
	}
	
	for(int i = 1; i < n; i++) {
		cin >> x;
		for(int j = 0; j < m; j++) {
			dp[j][i%2] = 0;
			if(x == 0 || j == x-1) {
				dp[j][i%2] = dp[j][(i-1)%2];
				if(j > 0)
					dp[j][i%2] = (dp[j][i%2]+dp[j-1][(i-1)%2])%1000000007;
				if(j < m-1) 
					dp[j][i%2] = (dp[j][i%2]+dp[j+1][(i-1)%2])%1000000007;
			}
		}
	}
	
	int ans = 0;
	for(int j = 0; j < m; j++) 
		ans = (ans+dp[j][(n-1)%2])%1000000007;
	cout << ans << '\n';
	return 0;
}