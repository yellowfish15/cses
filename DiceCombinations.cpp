#include <iostream>

using namespace std;
using ll = long long;

ll dp[2000005]{0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	
	dp[0] = 1;
	for(int i = 0; i<N; i++)
		for(int j = 1; j <= 6; j++)
			dp[i+j] += dp[i]%1000000007;
		
	cout << dp[N]%1000000007 << '\n';
}