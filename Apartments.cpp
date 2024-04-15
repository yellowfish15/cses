/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAX_N 100005

using namespace std;
using ll = long long;
const ll INF = (1ll << 57);
const ll NEG_INF = (-1ll << 57);

int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0; i < M; i++)
		cin >> b[i];
	
	sort(a, a+N);
	sort(b, b+M);
	
	int count = 0;
	int j = 0;
	for(int i = 0; i < N; i++)
		for(; j<M; j++) {
			if(b[j] > a[i]+K)
				break;
			if(abs(a[i]-b[j]) <= K) {
				count++;
				j++;
				break;
			}
		}
	cout << count << '\n';
}