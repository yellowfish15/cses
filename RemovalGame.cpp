#include <cstring>
#include <iostream>
#include <utility>

using namespace std;
using ll = long long;

pair<ll, ll> dp[5000][5000][2];
bool seen[5000][5000][2];
ll arr[5000];

pair<ll, ll> rec(int l, int r, int p) {
	if(seen[l][r][p])
		return dp[l][r][p];
	if(l == r)
		dp[l][r][p] = {arr[l], 0};
	else {
		pair<ll, ll> r1 = rec(l+1, r, !p);
		r1.second += arr[l];
		pair<ll, ll> r2 = rec(l, r-1, !p);
		r2.second += arr[r];
		if(r1.second > r2.second)
			dp[l][r][p] = {r1.second, r1.first};
		else if(r2.second > r1.second)
			dp[l][r][p] = {r2.second, r2.first};
		else
			dp[l][r][p] = {r1.second, min(r1.first, r2.first)};
	}
	seen[l][r][p] = true;
	return dp[l][r][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(seen, false, sizeof(seen));
	
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << rec(0, n-1, 0).first << '\n';
	
	return 0;
}

