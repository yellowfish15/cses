#include <iostream>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	ll lp = 96;
	for(ll k = 1; k <= n; k++) {
		if(k == 1) cout << 0 << '\n';
		else if(k == 2) cout << 6 << '\n';
		else if(k == 3) cout << 28 << '\n';
		else if(k == 4) cout << 96 << '\n';
		else {
			lp += 2*k*k*k-3*k*k-7*k+16;
			cout << lp << '\n';
		}
	}
	return 0;
}