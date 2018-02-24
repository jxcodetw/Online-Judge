#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	std::vector<int> s;
	std::vector<int> pos;
	int n;
	while(std::cin >> n) {
		s.push_back(n);
	}

	std::vector<int> v;
	v.push_back(s[0]);
	pos.push_back(1);

	for(int i=1;i<s.size();++i) {
		if (s[i] > v.back()) {
			v.push_back(s[i]);
			pos.push_back(v.size());
		} else {
			std::vector<int>::iterator it = lower_bound(v.begin(), v.end(), s[i]);
			pos.push_back(std::distance(v.begin(), it)+1);
			*it = s[i];
		}
	}

	std::vector<int> ans;
	int nth = v.size();
	for(int i=pos.size()-1;i>=0;--i) {
		if (pos[i] == nth) {
			nth -= 1;
			ans.push_back(s[i]);
		}
	}

	std::cout << v.size() << std::endl;
	std::cout << '-' << std::endl;
	for(int i=ans.size()-1;i>=0;--i) {
		std::cout << ans[i] << std::endl;
	}
	return 0;
}
