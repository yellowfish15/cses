#include <iostream>

int main() {
	int n; std::cin >> n;
	int s = 0;
	for(int i = 5; i <= n; i *= 5)
		s += n/i;
	std::cout << s << '\n';
}