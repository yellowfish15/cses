#include <iostream>

using namespace std;
using ll = long long;

#define M 1000000007

ll fac[1000001]; // factorial
ll inv[1000001]; // inverse

int main() {
	fac[0] = inv[0] = 1;
	for(int i = 1; i < 1000001; i++) {
		fac[i] = (i*fac[i-1])%M;
		ll res = 1, a = fac[i];
		for(int e = 1000000005; e > 0; e >>= 1) {
			if(e & 1) 
				res = (res*a)%M;
			a = (a*a)%M;
		}
		inv[i] = res;
	}
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int tt = 0; tt < N; tt++) {
		int a, b;
		cin >> a >> b;
		ll ans = (((fac[a]*inv[b])%M)*inv[a-b])%M;
		cout << ans << '\n';
	}
}