#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int arr[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr+n);
	
	int l = 0, r = n-1, ans = 0;
	while(l < r) {
		if(arr[l] + arr[r] <= x)
			l++;
		r--;
		ans++;
	}
	if(l == r)
		ans++;
	
	cout << ans << '\n';
	return 0;
}