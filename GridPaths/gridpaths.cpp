/*
	> g++ -o main [filename].cpp
	> main
*/

#include <iostream>

using namespace std;

char input[48];
bool vis[7][7];

int recur(int row, int col, int idx, char dir) {
	bool up = row > 0 && !vis[row-1][col];
	bool down = row < 6 && !vis[row+1][col];
	bool left = col > 0 && !vis[row][col-1];
	bool right = col < 6 && !vis[row][col+1];
	
	if(idx > -1 && input[idx] != '?' && dir != input[idx])
		return 0;
	if(row == 6 && col == 0 && idx < 47)
		return 0;
	if((!down && !up && left && right) || (!left && !right && down && up))
		return 0;
	if(idx == 47)
		return 1;
	
	vis[row][col] = true;
	
	int sum = 0;
	if(up)
		sum += recur(row-1, col, idx+1, 'U');
	if(down)
		sum += recur(row+1, col, idx+1, 'D');
	if(left)
		sum += recur(row, col-1, idx+1, 'L');
	if(right)
		sum += recur(row, col+1, idx+1, 'R');
	
	vis[row][col] = false;
	return sum;
}

int main() {
	for(int i = 0; i < 48; i++)
		cin >> input[i];
	for(int i = 0; i < 7; i++)
		for(int j = 0; j < 7; j++)
			vis[i][j] = false;
	cout << recur(0, 0, -1, '?') << '\n';
	return 0;
}