#include <iostream>
#define M 1000000007
using namespace std;

int dp[10][1000][1024] = {0};

int main() {
	int n, m;
	cin >> n >> m;
	
	// r == 0
	for (int c = 0, s = 1<<(n-1); c < n; c++, s>>=1) {
		dp[c][0][0] = 1;
		if(c > 0) {
			for(int b = s; b < (1<<n); b+=s) {
				if (!(b&s)) {
					dp[c][0][b] = (dp[c][0][b]+dp[c-1][0][b])%M;
				} else if (b&(s<<1)) {
					dp[c][0][b] = (dp[c][0][b]+dp[c-1][0][b^s^(s<<1)])%M;
				}
			}
		}
	}
	
	for (int r = 1; r < m; r++) {
		for (int c = 0, s = 1<<(n-1); c < n; c++, s>>=1) {
			for (int b = 0; b<(1<<n); b++) {
				if (c == 0) 
					dp[c][r][b] = dp[n-1][r-1][b^s];
				else {
					dp[c][r][b] = dp[c-1][r][b^s];
					if (b&s && (b&(s<<1))) 
						dp[c][r][b] = (dp[c][r][b]+dp[c-1][r][b^(s<<1)])%M;
				}
			}
		}
	}
	
	cout << dp[n-1][m-1][(1<<n)-1] << '\n';
	return 0;
}