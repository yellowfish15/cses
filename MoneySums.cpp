#include <iostream>

using namespace std;

bool dp[100001] = {false};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	dp[0] = true;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		for(int j = 100000; j-x >= 0; j--)
			dp[j] |= dp[j-x];
	}
	
	int cnt = 0;
	for(int i = 1; i <= 100000; i++)
		if(dp[i])
			cnt++;
	cout << cnt << '\n';
	for(int i = 1; i <= 100000; i++)
		if(dp[i])
			cout << i << ' ';
	cout << '\n';
	return 0;
}