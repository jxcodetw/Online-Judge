#include <iostream>
#include <stack>

int T[500+10][6];
int dice[500+10][6];
std::pair<int, int> path[500+10][6];

std::string sides[6] = {"front", "back", "left", "right", "top", "bottom"};

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N;
	int case_count = 1;
	while(std::cin >> N && N != 0) {
		std::fill(&T[0][0], &T[0][0] + sizeof(T)/sizeof(T[0][0]), 0);
		int mx = 0, ans_d, ans_s;
		for(int t=0;t<N;++t) {
			for(int i=0;i<6;++i) {
				path[t][i].first = -1;
				path[t][i].second = -1;
			}
		}
		for(int t=0;t<N;++t) {
			for(int i=0;i<6;++i) {
				std::cin >> dice[t][i];
				T[t][i] = 1;
			}
			for(int j=0;j<6;++j) {
				int jp = (j % 2 == 0) ? j+1 : j-1;
				for(int i=0;i<t;++i) {
					for(int k=0;k<6;++k) {

						if (dice[t][jp] == dice[i][k]) {
							if (1+T[i][k] >= T[t][j]) {
								T[t][j] = 1+T[i][k];

								path[t][j].first = i;
								path[t][j].second = k;
								if (T[t][j] > mx) {
									mx = T[t][j];
									ans_d = t;
									ans_s = j;
								}
							}
						}
					}
				}

			}
		}
		std::stack<std::string> ans_lines;
		while (ans_d != -1) {
			int side = (ans_s % 2 == 0) ? ans_s+1 : ans_s-1;
			ans_lines.push(std::to_string(ans_d+1) + ' ' + sides[side]);
			int a = path[ans_d][ans_s].first;
			int b = path[ans_d][ans_s].second;
			ans_d = a;
			ans_s = b;
		}
		std::cout << "Case #" << case_count++ << std::endl;
		std::cout << mx << std::endl;
		while(!ans_lines.empty()) {
			std::cout << ans_lines.top() << std::endl;
			ans_lines.pop();
		}
		std::cout << std::endl;
	}
	return 0;
}
