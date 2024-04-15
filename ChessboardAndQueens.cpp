#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

bool board[8][8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			if(c == '*')
				board[i][j] = false;
			else 
				board[i][j] = true;
		}
	
	int pos[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int ans = 0;
	OUT: while (next_permutation(pos, pos+8)) {
		for(int i = 0; i < 8; i++)
			if(!board[i][pos[i]])
				goto OUT;
		for(int i = 0; i < 8; i++)
			for(int j = 1; i+j < 8; j++)
				if(pos[i+j] == pos[i]+j || pos[i+j] == pos[i]-j)
					goto OUT;
		ans++;
	}
	cout << ans << '\n';
}