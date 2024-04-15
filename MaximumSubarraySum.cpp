#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	long long s = 0, a = -1000000000;
	for(int i = 0; i < n; i++) {
		long long x; cin >> x;
		s += x;
		if(s > a) a = s;
		if(s < 0) s = 0;
	}
	cout << a << '\n';
	return 0;
}