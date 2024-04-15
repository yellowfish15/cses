#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define INF 2000000
char grid[1000][1001];
int steps[1000][1001];
int path[1000][1001][2];
struct State {
	int r, c;
};

int main() {
	int N, M; cin >> N >> M;
	int sR, sC;
	queue<State> q;
	for(int i = 0; i < N; i++) {
		cin >> grid[i];
		for(int j = 0; j < M; j++) {
			steps[i][j] = INF;
			path[i][j][0] = path[i][j][1] = INF;
			if(grid[i][j] == 'M') {
				steps[i][j] = 0;
				q.push({i, j});
			} else if(grid[i][j] == 'A') {
				sR = i;
				sC = j;
			}
		}
	}
	while(!q.empty()) {
		State s = q.front();
		q.pop();
		if(s.r > 0 && grid[s.r-1][s.c] != '#' && steps[s.r-1][s.c] == INF) {
			steps[s.r-1][s.c] = steps[s.r][s.c] + 1;
			q.push({s.r-1, s.c});
		}
		if(s.r < N-1 && grid[s.r+1][s.c] != '#' && steps[s.r+1][s.c] == INF) {
			steps[s.r+1][s.c] = steps[s.r][s.c] + 1;
			q.push({s.r+1, s.c});
		}
		if(s.c > 0 && grid[s.r][s.c-1] != '#' && steps[s.r][s.c-1] == INF) {
			steps[s.r][s.c-1] = steps[s.r][s.c] + 1;
			q.push({s.r, s.c-1});
		}
		if(s.c < M-1 && grid[s.r][s.c+1] != '#' && steps[s.r][s.c+1] == INF) {
			steps[s.r][s.c+1] = steps[s.r][s.c] + 1;
			q.push({s.r, s.c+1});
		}
	}
	path[sR][sC][0] = 0; // distance
	q.push({sR, sC});
	while(!q.empty()) {
		State s = q.front();
		int dist = path[s.r][s.c][0]+1;
		q.pop();
		if(s.r == 0 || s.r==N-1 || s.c == 0 || s.c==M-1) { // reached border
			cout << "YES\n";
			stack<char> stk;
			while(path[s.r][s.c][1] != INF) {
				char dir = (char)path[s.r][s.c][1];
				stk.push(dir);
				if(dir == 'U') 
					s.r++;
				else if(dir == 'D') 
					s.r--;
				else if(dir == 'L')
					s.c++;
				else 
					s.c--;
			}
			cout << stk.size() << '\n';
			while(!stk.empty()) {
				cout << stk.top();
				stk.pop();
			}
			cout << '\n';
			return 0;
		}
		if(grid[s.r-1][s.c] != '#' && dist < steps[s.r-1][s.c] && path[s.r-1][s.c][0] == INF) {
			path[s.r-1][s.c][0] = dist;
			path[s.r-1][s.c][1] = 'U';
			q.push({s.r-1, s.c});
		}
		if(grid[s.r+1][s.c] != '#' && dist < steps[s.r+1][s.c] && path[s.r+1][s.c][0] == INF) {
			path[s.r+1][s.c][0] = dist;
			path[s.r+1][s.c][1] = 'D';
			q.push({s.r+1, s.c});
		}
		if(grid[s.r][s.c-1] != '#' && dist < steps[s.r][s.c-1] && path[s.r][s.c-1][0] == INF) {
			path[s.r][s.c-1][0] = dist;
			path[s.r][s.c-1][1] = 'L';
			q.push({s.r, s.c-1});
		}
		if(grid[s.r][s.c+1] != '#' && dist < steps[s.r][s.c+1] && path[s.r][s.c+1][0] == INF) {
			path[s.r][s.c+1][0] = dist;
			path[s.r][s.c+1][1] = 'R';
			q.push({s.r, s.c+1});
		}
	}
	cout << "NO\n";
	return 0;
}