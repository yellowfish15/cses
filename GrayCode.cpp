#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<string> v;
	v.push_back("");
	for(int i = 0; i < N; i++) {
		for(int j = v.size()-1; j >= 0; j--)
			v.push_back(v[j]);
		for(int j = 0; j < v.size(); j++) {
			if(j < v.size()/2)
				v[j] += '0';
			else
				v[j] += '1';
		}
	}
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}