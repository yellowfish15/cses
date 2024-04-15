#include <iostream>
using namespace std;
int c[200001] = {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int s = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x > c[s])
			c[++s] = x;
		else {
			int l = 0, h = s-1, t = 0;
			while(l <= h) {
				int m = (l+h)>>1;
				if(c[m] < x) {
					t = m; 
					l = m+1;
				} else {
					h = m-1;
				}
			}
			c[t+1] = min(c[t+1], x);
		}
	}
	cout << s << '\n';
	return 0;
}