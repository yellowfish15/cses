#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;

struct Query {
	int type, a, b;
};

#define UP 600005

vector<int> v;
unordered_map<int, int> m;
Query qs[200001]; 
int s[200001];
int tree[UP] = {0};
 
int get(int x) {
	int sum = 0;
	for(; x > 0; x-=x&(-x))
		sum += tree[x];
	return sum;
}
 
void update(int x, int k) {
	for(; x < UP; x+=x&(-x)) 
		tree[x] += k;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++) {
		cin >> s[i];
		v.push_back(s[i]);
	}
	
	for(int q = 0; q < Q; q++) {
		char type;
		int a, b;
		cin >> type >> a >> b;
		qs[q] = {type=='?', a, b};
		v.push_back(b);
		if(type=='?')
			v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
		m[v[i]] = i+1;
	
	for(int i = 1; i <= N; i++) {
		s[i] = m[s[i]];
		update(s[i], 1);
	}
	
	for(int q = 0; q < Q; q++) {
		int a = qs[q].a;
		int b = qs[q].b;
		if(qs[q].type) {
			cout << get(m[b]) - get(m[a]-1) << '\n';
		} else {
			update(s[a], -1);
			s[a] = m[b]; 
			update(s[a], 1);
		}
	}
	
}
