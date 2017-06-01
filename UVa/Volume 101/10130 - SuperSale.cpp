#include <iostream>
#include <algorithm>
#include <cstring>

int P[1010], W[1010], dp[1010][40];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int T, N, G, MW;
    std::cin >> T;
    while(T--) {
        std::cin >> N;
        for(int i=1;i<=N;++i) {
            std::cin >> P[i] >> W[i];
        }
        
        std::cin >> G;
        int sum = 0;
        while(G--) {
            std::cin >> MW;
            
            for(int i=1;i<=N;++i) {
                for(int j=0;j<W[i];++j) {
                    dp[i][j] = dp[i-1][j];
                }
                for(int j=W[i];j<=MW;++j) {
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-W[i]] + P[i]);
                }
            }
            
            sum += dp[N][MW];
        }
        
        std::cout << sum << std::endl;
    }
    return 0;
}
