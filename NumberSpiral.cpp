#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long x, y; cin >> x >> y; x--; y--;
		if(x > y) cout << (x*(x+1)+1 - ((x%2==0)?(x-y):(y-x))) << '\n';
		else cout << (y*(y+1)+1 - ((y%2==0)?(x-y):(y-x))) << '\n';
	}
	return 0;
}