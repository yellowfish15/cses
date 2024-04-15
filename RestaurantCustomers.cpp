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
const ll INF = (1ll << 58);
const ll NEG_INF = (-1ll << 58);

struct Pair {
	int time;
	bool is_start;
	
	bool operator < (const Pair& oth) const
    {
        return (time < oth.time);
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<Pair> v;
	for(int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({start, true});
		v.push_back({end, false});
	}
	sort(v.begin(), v.end());
	int count = 0, ans = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].is_start)
			count++;
		else
			count--;
		ans = max(count, ans);
	}
	cout << ans << '\n';
	
}