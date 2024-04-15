#include <iostream>

using namespace std;
using ll = long long;

ll calc(char * n, bool &works) {
	ll dp[20][10] = {0};
	ll count = 2; // assume 0 and n are valid
	char prev = n[0]-'0';
	if(prev == 0)
		return 1;
	for(char d = prev-1; d > 0; d--)
		dp[0][d]++;
	int i = 1;
	for(; n[i] != 0; i++) {
		char curr = n[i]-'0';
		for(char x = 0; x < 10; x++) {
			if(x > 0)
				dp[i][x]++;
			if(count == 2 && x < curr && x != prev) 
				dp[i][x]++;
		}
		if(curr == prev) {
			works = false;
			count = 1;
		}
		for(char x = 0; x < 10; x++) {
			for(char y = 0; y < 10; y++) {
				if(x == y)
					continue;
				dp[i][x] += dp[i-1][y];
			}
		}
		prev = curr;
	}
	for(char x = 0; x < 10; x++)
		count += dp[i-1][x];
	return count;
}

int main() {
	bool v = true;
	ll ans = 0;
	char n[19]; cin >> n;
	ans -= calc(n, v);
	if(v)
		ans++;
	cin >> n;
	ans += calc(n, v);
	cout << ans << '\n';
	return 0;
}