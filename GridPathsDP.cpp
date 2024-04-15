#include <iostream>
using namespace std;
int dp[1001]={0}; 
char b[1002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	dp[0]=1;
	for(int i=0;i<n;i++){
		cin>>b;
		for(int j=1;j<=n;j++)
			if(b[j-1]=='.')dp[j]=(dp[j]+dp[j-1])%1000000007;
			else dp[j]=0;
		dp[0]=0;
	}
	cout<<dp[n]<<'\n';
}