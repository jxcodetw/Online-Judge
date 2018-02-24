#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int K;
	std::cin >> K;
	while(K--) {
		std::vector<int> seq;
		int m, n, num;
		std::cin >> m >> n;
		for(int i=0;i<m;++i) {
			std::cin >> num;
			seq.push_back(num);
		}

		std::vector<int> queue;
		int s = 0, g = 0;
		while(n--) {
			std::cin >> num;
			while (queue.size() < num) {
				queue.insert(lower_bound(queue.begin(), queue.end(), seq[s]), seq[s]);
				s += 1;
			}
			std::cout << queue[g++] << std::endl;
		}
		if (K != 0) {
			std::cout << std::endl;
		}
	}

	return 0;
}
