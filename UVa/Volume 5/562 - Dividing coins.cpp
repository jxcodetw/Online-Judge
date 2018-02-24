#include <iostream>
#include <vector>

int coin[110];
int dp[25010];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N; std::cin >> N;

	while (N--) {
		int M; std::cin >> M;
		int sum = 0;
		for(int i=1;i<=M;++i) {
			std::cin >> coin[i];
			sum += coin[i];
		}

		int half = sum / 2;

		for(int i=0;i<=half;++i) {
			dp[i] = 0;
		}
		for(int i=1;i<=M;++i) {
			for(int j=half;j>0;--j) {
				if (j-coin[i] >= 0) {
					dp[j] = std::max(dp[j], dp[j-coin[i]] + coin[i]);
				}
			}
		}
		std::cout << sum - dp[half] * 2 << std::endl;
	}
	return 0;
}
