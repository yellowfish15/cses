#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x; cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		int v; cin >> v;
		if(v > x)
			continue;
		if(m.find(x-v) != m.end()) {
			cout << m[x-v] << ' ' << i << '\n';
			return 0;
		}
		m[v] = i;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}