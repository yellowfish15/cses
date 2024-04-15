#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	cin >> N;
	ll m = 0, tot = 0;;
	for(int i = 0; i < N; i++) {
		ll v;
		cin >> v;
		tot += v;
		m = max(m, v);
	}
	if(tot-m < m)
		cout << 2*m << '\n';
	else
		cout << tot << '\n';
}