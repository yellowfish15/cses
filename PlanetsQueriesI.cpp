#include <iostream>

using namespace std;
using ll = long long;

#define LOG 31
int par[200001][LOG];

int kth(int x, int k) {
	for(int j = 0; k > 0; j++, k>>=1)
		if(k&1)
			x = par[x][j];
	return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++) {
		int child;
		cin >> child;
		par[i][0] = child; 
	}		
	
	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= N; i++)
			par[i][j] = par[par[i][j-1]][j-1];
		
	for(int i = 0; i < Q; i++) {
		int x, k;
		cin >> x >> k;
		cout << kth(x,k) << '\n';
	}
}