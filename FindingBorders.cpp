#include <iostream>

using namespace std;
using ll = long long;

#define MOD 1000000007
#define B1 31
#define B2 37

char s[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> s;
	
	int N = 0;
	for(;s[N] != '\0'; N++); // get size of string
	
	ll h1 = 0, h2 = 0, h3 = 0, h4 = 0;
	ll b1 = 1, b2 = 1;
	for(int i = 0; i < N-1; i++) {
		h1 = ((h1*B1)+s[i]-97)%MOD;
		h2 = ((h2*B2)+s[i]-97)%MOD;
		h3 = (h3 + (s[N-i-1]-97)*b1)%MOD;
		h4 = (h4 + (s[N-i-1]-97)*b2)%MOD;
		b1 = (b1*B1)%MOD;
		b2 = (b2*B2)%MOD;
		if(h1 == h3 && h2 == h4)
			cout << i+1 << ' ';
	}
	cout << '\n';
}