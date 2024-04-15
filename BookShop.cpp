#include <iostream>

using namespace std;

int dp[100001] = {0};
int pr[1000]; // prices

int main() {
	int n, x;
	cin >> n >> x;
	
	for(int i = 0; i < n; i++)
		cin >> pr[i]; // price
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int pg;
		cin >> pg;
		if(pr[i] > x)
			continue;
		for(int j = x; j >= pr[i]; j--)
			if(dp[j-pr[i]] > 0) {
				dp[j] = max(dp[j], dp[j-pr[i]]+pg);
				ans = max(ans, dp[j]);
			}
		dp[pr[i]] = max(dp[pr[i]], pg);
		ans = max(ans, pg);
	}
	cout << ans << '\n';
	return 0;
}