#include <iostream>

using namespace std;

int main () {
	int t; cin >> t;
	for(;t>0;t--) {
		int a, b; cin >> a >> b;
		if (a > b) {
			int c = a;
			a = b;
			b = c;
		}
		if((2*a - b)%3 == 0) {
			int k = (2*a-b)/3;
			if(k < 0)
				cout << "NO\n";
			else
				cout << "YES\n";
		} else 
			cout << "NO\n";
	}
}