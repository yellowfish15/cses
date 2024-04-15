#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

struct Trie {
	bool word = false;
	unordered_map<char, Trie*> map;
};

char s1[5005]; // big string
char s2[1000005]; // buffer
ll dp[5005] = {0}; // dp array
Trie * root = new Trie();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> s1;
	int K;
	cin >> K;
	
	for(int i = 0; i < K; i++) {
		Trie * curr = root;
		cin >> s2;
		for(int j = 0; s2[j] != '\0'; j++) {
			if(curr->map.find(s2[j]) == curr->map.end())
				curr->map[s2[j]] = new Trie();
			curr = curr->map.find(s2[j])->second;
		}
		curr->word = true;
	}
	
	int i = 0;
	for(; s1[i] != '\0'; i++) {
		int p = i > 0 ? dp[i-1] : 1;
		Trie * curr = root;
		for(int j = i; s1[j] != '\0'; j++) {
			if(curr->map.find(s1[j]) == curr->map.end())
				break;
			curr = curr->map.find(s1[j])->second;
			if(curr->word)
				dp[j] = (dp[j]+p)%1000000007;
		}
	}
	
	cout << dp[i-1] << '\n';
	
}