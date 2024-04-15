#include <iostream>
#include <set>

using namespace std;

int main() {
	int n,m; cin >> n >> m;
	multiset<int> s;
	for(int i = 0; i < n; i++) {
		int val; cin >> val;
		s.insert(val);
	}
	for(int i = 0; i < m; i++) {
		int p; cin >> p;
		auto it = s.lower_bound(p);
		if(it == s.end() && s.size() > 0)
			it--;
		else if(it != s.end() && *it > p)
			it--;
		if(it != s.end() && *it <= p) {
			cout << *it << '\n';
			s.erase(it);
		} else 
			cout << "-1\n";
	}
	return 0;
}