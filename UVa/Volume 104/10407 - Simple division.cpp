#include <iostream>
#include <vector>


int seq[1000+10];

int gcd(int a, int b) {
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}

	while(b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N, idx, mn;
	while(std::cin >> N && N != 0) {
		idx = 0;
		mn = N;
		do {
			seq[idx++] = N;
			if (N < mn) {
				mn = N;
			}
		} while(std::cin >> N && N != 0);

		int g = 0;
		for(int i=0;i<idx;++i) {
			g = gcd(seq[i] - mn, g);
		}
		std::cout << g << std::endl;
	}

	return 0;
}
