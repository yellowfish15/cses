#include <iostream>

using namespace std;
using ll = long long;

#define MAXN 200005

ll tree[MAXN] = {0}; // fenwick tree
ll arr[MAXN]; // array of values

// add "u" to range [k, N]
void update(int k, ll u) {
	for(; k < MAXN; k += (-k)&k) 
		tree[k] += u;
}

// get sum from [1, k]
ll get(int k) {
	ll sum = 0;
	for(; k > 0; k -= (-k)&k)
		sum += tree[k];
	return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++) cin >> arr[i];

	for(int q = 0; q < Q; q++) {
		int type;
		cin >> type;
		if(type == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			update(a, u);
			update(b+1, -u);
		} else {
			int k;
			cin >> k;
			cout << arr[k] + get(k) << '\n';
		}
	}

}