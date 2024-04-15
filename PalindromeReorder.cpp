#include <iostream>

using namespace std;

char s[1000001];
int c[26] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	int l = 0, r = 0;
	while(s[r] != 0) {
		c[s[r]-'A']++;
		r++;
	}
	r--;
	int m = -1;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < c[i]>>1; j++) {
			s[l++] = i+'A';
			s[r--] = i+'A';
		}
		if(c[i]%2 == 1) {
			if(m == -1) {
				m = i;
			} else {
				cout << "NO SOLUTION\n";
				return 0;
			}
		}
	}
	if(m != -1) 
		s[l] = m+'A';
	cout << s << '\n';
	
}