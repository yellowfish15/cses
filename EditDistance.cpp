#include <iostream>

using namespace std;

char s1[5001], s2[5001];
int dp[5001][5001];

int main() {
	cin >> s1 >> s2;
	
	for(int i = 0; i < 5001; i++) {
		dp[i][0] = i;
		dp[0][i] = i;
	}
	int i, j;
	for(i = 0; s1[i] != '\0'; i++) {
		for(j = 0; s2[j] != '\0'; j++) {
			dp[i+1][j+1] = min(dp[i][j+1]+1, dp[i+1][j]+1);
			if(s1[i] == s2[j])
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			else 
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
		}
	}
	cout << dp[i][j] << '\n';
	return 0;
}