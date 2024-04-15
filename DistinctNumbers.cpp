#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	set<int> s;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	
	cout << s.size() << '\n';
	
	return 0;
}