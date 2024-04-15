/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;
const ll INF = (1ll << 58);
const ll NEG_INF = (-1ll << 58);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll N, ans;
	cin >> N;
	ans = (N)*(N+1)/2;
	while(N-->1) {
		int x;
		cin >> x;
		ans -= x;
	}
	cout << ans << '\n';
}