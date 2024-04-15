/*
	> g++ -o main [filename].cpp
	> main
	
	(or alt+x in notepad++) 
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;
const ll INF = (1ll << 58);
const ll NEG_INF = (-1ll << 58);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int ans = 1, curr = 1;
	string s;
	cin >> s;
	for(int i = 1; i < s.length(); i++) {
		if(s[i] == s[i-1]) {
			curr++;
			ans = max(ans, curr);
		} else
			curr = 1;
	}
	cout << ans << '\n';
	
}