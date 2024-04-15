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

ll arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	
	ll l = 1, h = 1ll << 55;
	while(l <= h) {
		ll m = (l+h)>>1;
		int k = 0;
		ll sum = 0;
		for(int i = 0; i < N; i++) {
			sum += arr[i];
			if(arr[i] > m)
				k = K;
			if(sum > m) {
				k++;
				sum = arr[i];
			}
		}
		if(k < K) {
			h = m-1;
		} else {
			l = m+1;
		}
	}
	cout << l << '\n';
}