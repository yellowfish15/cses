#include <iostream>

using namespace std;
using ll = long long;

#define INF 1000000001

int tree[524290];
int arr[200001];

int build(int curr, int l, int r) {
	if(l==r)
		tree[curr] = arr[l];
	else {
		int m = (l+r)/2;
		tree[curr] = min(build(curr*2+1, l, m), build(curr*2+2, m+1, r));
	}
	return tree[curr];
}

// update array at position i to value u
int update(int i, int u, int curr, int l, int r) {
	if(i < l || i > r)
		return tree[curr];
	if(l==r) {
		if(l == i)
			tree[curr] = u;
	} else {
		int m = (l+r)/2;
		tree[curr] = min(update(i, u, curr*2+1, l, m), update(i, u, curr*2+2, m+1, r));
	}
	return tree[curr];
}

// get minimum from [a,b]
int minimum(int a, int b, int curr, int l, int r) {
	if(l >= a && r <= b)
		return tree[curr];
	if(r < a || l > b) // outside range
		return INF;
	int m = (l+r)/2;
	return min(minimum(a, b, curr*2+1, l, m), minimum(a, b, curr*2+2, m+1, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++) cin >> arr[i];

	build(0, 1, N);

	while(Q-->0) {
		int q, a, b;
		cin >> q >> a >> b;
		if(q == 1)
			update(a, b, 0, 1, N);
		else
			cout << minimum(a, b, 0, 1, N) << '\n';
	}
}