#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	while(N-->0) {
		int x, cnt = 0;
		cin >> x;
		for(int i = 1; i*i <= x; i++) {
			if(x % i == 0) {
				cnt++;
				if(x/i != i)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
}