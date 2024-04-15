#include <algorithm>
#include <iostream>

using namespace std;

pair<int,int> a[200001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n, cmp);
	int ans = 1, end = a[0].second;
	for(int i = 1; i < n; i++) {
		if(a[i].first >= end) {
			end = a[i].second;
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}