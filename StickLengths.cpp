/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAX_N 100005

using namespace std;
using ll = long long;
const ll INF = (1ll << 58);
const ll NEG_INF = (-1ll << 58);

ll a[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	ll avg = 0;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		avg += a[i];
	}
	sort(a, a+N);
	avg = a[N/2];
	if(N%2 == 0)
		avg = (avg+a[N/2-1])/2;
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		ans += abs(avg-a[i]);
	}
	cout << ans << '\n';
}