#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll dp[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<vector<ll>> p(n, vector<ll>(3));
	
	for(int i = 0; i < n; i++)
		cin >> p[i][0] >> p[i][1] >> p[i][2];

	sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
		if(a[1] == b[1])
			return a[0] < b[0];
		return a[1] < b[1];
	});
		
	dp[0] = p[0][2];
	for(int i = 1; i < n; i++) {
		dp[i] = max(p[i][2], dp[i-1]); // ignore this project
		// pick this project
		int l = 0, h = n-1, t = -1;
		while(l <= h) {
			int m = (l+h)>>1;
			if(p[m][1] < p[i][0]) {
				if(m > t) t = m;
				l = m+1;
			} else
				h = m-1;
		}
		if(t > -1)
			dp[i] = max(dp[i], p[i][2] + dp[t]);
	}
	cout << dp[n-1] << '\n';
	
	return 0;
}