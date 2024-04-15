#include <iostream>

using namespace std;
using ll = long long;

#define M 1000000007
ll dp[1000001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i < 1000001; i++) {
		dp[i][0] = ((dp[i-1][0]<<1) + dp[i-1][1])%M;
		dp[i][1] = ((dp[i-1][1]<<2) + dp[i-1][0])%M;
	}
	
	while(t-->0) {
		int n; cin >> n;
		cout << ((dp[n][0]+dp[n][1])%M) << '\n';
	}
	
	return 0;
}