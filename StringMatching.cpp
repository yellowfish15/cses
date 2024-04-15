#include <iostream>

using namespace std;
using ll = long long;

#define MOD 998244353
#define B1 26
#define N 1000005

ll pow1[N];

char big[N];
char small[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	// precompute powers of B1 and B2
	pow1[0] = 1;
	for(int i = 1; i < N; i++)
		pow1[i] = (pow1[i-1]*B1)%MOD;
	
	cin >> big >> small;
	
	ll small_h1 = 0;
	int size = 0;
	for(; small[size] != '\0'; size++)
		small_h1 = ((small_h1*B1)+(small[size]-97))%MOD;
	
	ll big_h1 = 0;
	int ans = 0;
	// i = left, j = right
	for(int i = 0, j = 0; big[j] != '\0'; j++) {
		if(j-i == size) {
			big_h1 = (big_h1-((big[i]-97)*pow1[size-1])%MOD+MOD)%MOD;
			i++;
		}
		big_h1 = ((big_h1*B1)+(big[j]-97))%MOD;
		
		if(j-i == size-1 && big_h1 == small_h1)
			ans++;
	}
	
	cout << ans << '\n';
}