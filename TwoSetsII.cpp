#include <iostream>

using namespace std;

int dp[62626] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	
	int target = (n*(n+1))>>1;
	if(target%2 == 1) {
		cout << "0\n";
	} else {
		target >>= 1;
		dp[0] = 1;
		for(int i = 2; i <= n; i++)
			for(int j = target; j-i >= 0; j--)
				dp[j] = (dp[j] + dp[j-i])%1000000007;
		cout << dp[target] << '\n';
	}
	return 0;
}