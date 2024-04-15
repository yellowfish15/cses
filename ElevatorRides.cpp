#include <iostream>
#include <utility>

using namespace std;

int wi[20];
pair<int, int> dp[1<<20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x; cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> wi[i];
	for(int i = 0; i < (1<<n); i++)
		dp[i] = {21, 0};
	
	dp[0] = {0, x};
	for(int i = 0; i < (1<<n); i++) {
		for(int j = 0, b = 1; j < n; j++, b <<= 1) {
			if((b&i) == 0) {
				int r = dp[i].first;
				int w = dp[i].second+wi[j];
				if(w > x) {
					w = wi[j];
					r++;
				}
				if(r < dp[b+i].first) {
					dp[b+i].first = r;
					dp[b+i].second = w;
				} else if(r == dp[b+i].first && w < dp[b+i].second)
					dp[b+i].second = w;				
			}
		}
	}
	
	cout << dp[(1<<n)-1].first << '\n';
	return 0;	
}