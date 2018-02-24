#include <iostream>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N;
	while(std::cin >> N && N != 0) {
		int n, mx, acc;
		mx = -1e9;
		acc = -1;
		for(int i=0;i<N;++i) {
			std::cin >> n;
			if (acc < 0) {
				acc = n;
			} else {
				acc += n;
			}
			if (acc > mx) {
				mx = acc;
			}
		}
		if (mx > 0) {
			std::cout << "The maximum winning streak is " << mx << '.' << std::endl;
		} else {
			std::cout << "Losing streak." << std::endl;
		}
	}
	return 0;
}
