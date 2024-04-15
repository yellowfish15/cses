#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N; cin >> N;
	ll S = N*(N+1)>>1;
	if(S%2 == 1)
		cout << "NO\n";
	else {
		int fs = 0;
		ll S1 = S>>1; 
		for(int i = N; i > 0; i--) 
			if(S1 >= i) {S1 -= i; fs++;}
		if(S1 > 0)
			cout << "NO\n";
		else {
			cout << "YES\n" << fs << '\n';
			S1 = S>>1;
			for(int i = N; i > 0; i--) 
				if(S1 >= i) {S1 -= i; cout << i << ' ';}
			cout << '\n' << N-fs << '\n';
			S1 = S>>1;
			for(int i = N; i > 0; i--)
				if(S1 >= i) S1 -= i;
				else cout << i << ' ';
			cout << '\n';
		}
	}
}