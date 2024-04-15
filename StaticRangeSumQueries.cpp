#include <iostream>

using namespace std;
long long p[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q; cin >> n >> q;
	p[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> p[i]; 
		p[i] += p[i-1];
	}
	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << p[b]-p[a-1] << '\n';
	}
	return 0;
}