#include <iostream>

using namespace std;
using ll = long long;

#define MOD 1000000007

ll dp[1000005];
ll c[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, X;
	cin >> N >> X;
	
	for(int j = 0; j <= X; j++)
		dp[j] = 0;
	dp[0] = 1;
	
	for(int i = 1; i <= N; i++)
		cin >> c[i];
	
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= X; j++) {
			if(j-c[i] >= 0)
				dp[j] = (dp[j] + dp[j-c[i]])%MOD;
		}
	
	cout << dp[X] << '\n';
	
}