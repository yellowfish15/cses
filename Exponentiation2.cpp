#include <iostream>

using namespace std;
using ll = long long;

// raise a^k
ll pow(ll a, ll k, ll MOD) {
	if(k == 0)
		return 1;
	if(k == 1)
		return a;
	ll w = pow(a, k/2, MOD);
	if(k%2 == 0)
		return (w*w)%MOD;
	return (((w*w)%MOD)*a)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	while(N-->0) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll ans = pow(b, c, 1000000006);
		ans = pow(a, ans, 1000000007);
		cout << ans << '\n';
	}
}