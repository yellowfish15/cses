#include <iostream>

using namespace std;
using ll = long long;

ll dp[2000005]{0};
ll cs[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> cs[i];
	
	dp[0] = 1;
	for(int i = 0; i <= x; i++)
		for(int j = 0; j < n; j++)
			dp[i+cs[j]] += dp[i]%1000000007;
		
	cout << dp[x]%1000000007 << '\n';
	
}