#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define N 100001
vector<int> adj[N];
int in[N] = {0}, par[N], num[N] = {0};
bool src[N] = {false};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	
	queue<int> q;
	src[1] = true;
	for(int i = 1; i <= n; i++)
		if(!in[i]) {
			num[i] = 1;
			par[i] = 0;
			q.push(i);
		}
	
	while(!q.empty()) {
		int i = q.front(); q.pop();
		for(int c: adj[i]) {
			in[c]--;
			if(src[i] && num[i]+1 > num[c]) {
				num[c] = num[i]+1;
				par[c] = i;
				src[c] = true;
			}
			if(!in[c])
				q.push(c);
		}
	}
	
	if(!src[n]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	stack<int> s;
	s.push(n);
	while(s.top() > 1)
		s.push(par[s.top()]);
	
	cout << s.size() << '\n';
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return 0;
}