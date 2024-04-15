#include <iostream>
#include <vector>

using namespace std;

char g[1001][1001];
bool vis[1001][1001] = {false};

struct Tuple {
	int r, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> g[i];
	
	int id = 0;
	vector<Tuple> v;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == '.' && !vis[i][j]) {
				v.push_back({i, j});
				vis[i][j] = true;
				while(!v.empty()) {
					Tuple t = v.back();
					v.pop_back();
					if(t.r > 0 && !vis[t.r-1][t.c] && g[t.r-1][t.c] == '.') {
						v.push_back({t.r-1, t.c});
						vis[t.r-1][t.c] = true;
					} 
					if(t.r < n-1 && !vis[t.r+1][t.c] && g[t.r+1][t.c] == '.') {
						v.push_back({t.r+1, t.c});
						vis[t.r+1][t.c] = true;
					}
					if(t.c > 0 && !vis[t.r][t.c-1] && g[t.r][t.c-1] == '.') {
						v.push_back({t.r, t.c-1});
						vis[t.r][t.c-1] = true;
					}
					if(t.c < m-1 && !vis[t.r][t.c+1] && g[t.r][t.c+1] == '.') {
						v.push_back({t.r, t.c+1});
						vis[t.r][t.c+1] = true;
					}
				}
				id++;
			}
		}
	}
	cout << id << '\n';
	return 0;
}