#include <iostream>
using namespace std;
using ll = long long;
int main() {
	int N; cin >> N;
	ll a = 1;
	for(int c = 1 << 20; c > 0; c >>= 1) {
		if(c <= N) {
			a = (a*a)%1000000007;
			if(N&c) a = (a*2)%1000000007;
		}
	}
	cout << a << '\n';
}