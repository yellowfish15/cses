#include <iostream>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, prev = 0, x;
	cin >> N;
	ll ans = 0;
	for(;N>0;N--) {
		cin >> x;
		if(x < prev)
			ans += prev-x;	
		else
			prev = x;
	}
	cout << ans << '\n';
}