#include <iostream>

using namespace std;
using ll = long long;

int dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	
	if(a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	} else if(a == b) { 
		cout << 0;
		return 0;
	}
	
	dp[1][1] = 0;
	for(int i = 2; i < 501; i++) {
		dp[1][i] = i-1;
		dp[i][i] = 0;
	}
	
	for(int i = 2; i <= a; i++) {
		for(int j = i+1; j <= b; j++) {
			dp[i][j] = i*j;
			for(int k = 1; k <= (i>>1); k++)
				dp[i][j] = min(dp[i][j], dp[min(k, j)][max(k, j)] + dp[min(i-k, j)][max(i-k, j)]+1);
			for(int k = 1; k <= (j>>1); k++)
				dp[i][j] = min(dp[i][j], dp[min(i, k)][max(i, k)] + dp[min(i, j-k)][max(i, j-k)]+1);
		}
	}
	
	cout << dp[a][b] << '\n';
	
	return 0;
}