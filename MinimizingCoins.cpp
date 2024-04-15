#include <iostream>

using namespace std;
using ll = long long;

const ll INF = (1ll << 58);

ll dp[2000005];
ll coins[2000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, X;
	cin >> N >> X;
	
	for(int i = 0; i <= X; i++)
		dp[i] = INF;
	
	for(int i = 0; i < N; i++)
		cin >> coins[i];
	
	dp[0] = 0;
	for(int i = 0; i <= X; i++)
		for(int j = 0; j < N; j++)
			dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
		
	if(dp[X] == INF) {
		cout << -1 << '\n';
	} else {
		cout << dp[X] << '\n';
	}
}