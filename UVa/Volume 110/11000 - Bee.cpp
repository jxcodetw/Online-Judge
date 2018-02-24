#include <iostream>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N;
	while(std::cin >> N && N != -1) {
		long long int a = 0, b = 1;
		for(int i=0;i<N;++i) {
			long long int t = a;
			a = a + b;
			b = t + 1;
		}
		std::cout << a << ' ' << a+b << std::endl;
	}
	return 0;
}
