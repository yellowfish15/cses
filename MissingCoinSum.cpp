#include <algorithm>
#include <iostream>

using namespace std;

long long arr[200000];
long long x = 1;

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) {
		if(x >= arr[i])
			x += arr[i];
		else if(x < arr[i])
			break;
	}
	cout << x << '\n';
}