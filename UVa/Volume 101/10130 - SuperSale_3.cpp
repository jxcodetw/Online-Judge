#include <iostream>
#include <algorithm>
#include <cstring>

int P[1010], W[1010], dp[40];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int T, N, G, MW;
    std::cin >> T;
    while(T--) {
        std::cin >> N;
        for(int i=0;i<N;++i) {
            std::cin >> P[i] >> W[i];
        }
        
        std::cin >> G;
        int sum = 0;
        while(G--) {
            std::cin >> MW;
            
            memset(dp, 0, sizeof(dp));
            for(int i=0;i<N;++i) {
                for(int j=MW;j>=W[i];--j) {
                    dp[j] = std::max(dp[j], dp[j-W[i]] + P[i]);
                }
            }
            
            sum += dp[MW];
        }
        
        std::cout << sum << std::endl;
    }
    return 0;
}
