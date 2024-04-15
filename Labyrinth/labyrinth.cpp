/*
	> g++ -o main [filename].cpp
	> main
*/

#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

#define MOD 1000000007
#define MAX_N 100000

using namespace std;
using ll = long long;

char grid[1000][1000];
char vis[1000][1000];

struct State {
	int row, col;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	int aR = 0, aC = 0;
	for(int i = 0; i < N; i++) {
		cin >> grid[i];
		for(int j = 0; j < M; j++) {
			if(grid[i][j] == 'A') {
				aR = i;
				aC = j;
			}
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			vis[i][j] = ' ';
		}
	}
	bool found = false;
	
	queue<State> q;
	q.push({aR, aC});
	vis[aR][aC] = 0;
	while(!q.empty()) {
		State curr = q.front(); // next state on the queue
		q.pop();
		int r = curr.row;
		int c = curr.col;
		if(grid[r][c] == 'B') {
			aR = r;
			aC = c;
			found = true;
			break;
		}
		if(r > 0 && grid[r-1][c] != '#' && vis[r-1][c] == ' ') {
			q.push({r-1, c});
			vis[r-1][c] = 'U';
		}
		if(r < N-1 && grid[r+1][c] != '#' && vis[r+1][c] == ' ') {
			q.push({r+1, c});
			vis[r+1][c] = 'D';
		}
		if(c > 0 && grid[r][c-1] != '#' && vis[r][c-1] == ' ') {
			q.push({r, c-1});
			vis[r][c-1] = 'L';
		}
		if(c < M-1 && grid[r][c+1] != '#' && vis[r][c+1] == ' ') {
			q.push({r, c+1});
			vis[r][c+1] = 'R';
		}
	}
	
	if(!found) {
		cout << "NO" << '\n';
	} else {
		cout << "YES\n";
		stack<char> q2;
		while(vis[aR][aC] != 0) {
			char dir = vis[aR][aC];
			q2.push(dir);
			if(dir == 'R')
				aC--;
			else if(dir == 'L')
				aC++;
			else if(dir == 'U')
				aR++;
			else
				aR--;
		}
		cout << q2.size() << '\n';
		while(!q2.empty()) {
			cout << q2.top();
			q2.pop();
		}
		cout << '\n';
	}
	
}