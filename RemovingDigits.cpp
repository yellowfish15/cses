#include <iostream>

using namespace std;
using ll = long long;

int dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	dp[0] = 0;
	for(int i = 1; i < 1000001; i++) {
		int t = i;
		dp[i] = i;
		while(t > 0) {
			dp[i] = min(dp[i], dp[i-(t%10)]+1);
			t /= 10;
		}
	}
	
	int n;
	cin >> n;
	cout << dp[n] << '\n';
	
	return 0;
}