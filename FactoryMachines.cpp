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
const ll INF = (1ll << 60);
const ll NEG_INF = (-1ll << 60);

ll k[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, T;
	cin >> N >> T;
	
	for(int i = 0; i < N; i++)
		cin >> k[i];
	
	ll l = 1, h = INF;
	while(l < h) {
		ll m = (l+h)>>1;
		
		ll sum = 0;
		for(int i = 0; i < N; i++) {
			sum += m/k[i];
			if(sum >= T) {
				h = m;
				break;
			}
		}
		
		if(sum < T)
			l = m+1;
	}
	
	cout << l << '\n';
}