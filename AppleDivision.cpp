#include <iostream>

using namespace std;
using ll = long long;

ll arr[20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		cin>>arr[i];
		ans += arr[i];
	}
	
	for(int i = 1; i < 1<<N; i++) {
		ll sum1 = 0, sum2 = 0;
		for(int j = 0; j < N; j++) {
			if((i>>j)&1)
				sum1 += arr[j];
			else 
				sum2 += arr[j];
		}
		ans = min(ans, abs(sum1-sum2));
	}
	cout << ans << '\n';
}