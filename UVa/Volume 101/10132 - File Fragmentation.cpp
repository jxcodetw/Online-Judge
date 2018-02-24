#include <iostream>
#include <vector>
#include <map>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	std::string s;
	std::getline(std::cin, s);

	int N = stoi(s);
	std::getline(std::cin, s);
	while(N--) {
		std::vector<std::string> fragments;
		size_t mx = 0, mn = 1e9;
		while(std::getline(std::cin, s) && !s.empty()) {
			fragments.push_back(s);
			if (s.size() > mx) {
				mx = s.size();
			}
			if (s.size() < mn) {
				mn = s.size();
			}
		}

		size_t len = mx+mn;
		std::map<std::string, int> count;
		int mx_comb = 0;
		std::string ans, concate1, concate2;
		for(int i=0;i<fragments.size();++i) {
			for(int j=i+1;j<fragments.size();++j) {
				if (fragments[i].size() + fragments[j].size() == len) {
					concate1 = fragments[i] + fragments[j];
					concate2 = fragments[j] + fragments[i];
					int comb;
					comb = ++count[concate1];
					if (comb > mx_comb) {
						mx_comb = comb;
						ans = concate1;
					}
					comb = ++count[concate2];
					if (comb > mx_comb) {
						mx_comb = comb;
						ans = concate2;
					}
				}
			}
		}

		std::cout << ans << std::endl;
		if (N != 0) {
			std::cout << std::endl;
		}
	}
	return 0;
}
