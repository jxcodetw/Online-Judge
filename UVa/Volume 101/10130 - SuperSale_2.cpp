#include <iostream>
#include <algorithm>
#include <cstring>

int P[1010], W[1010], dp[2][40];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int T, N, G, MW, p;
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
            
            memset(dp[0], 0, sizeof(dp[0]));
            for(int i=1;i<=N;++i) {
                p = i & 1;
                for(int j=0;j<W[i];++j) {
                    dp[p][j] = dp[!p][j];
                }
                for(int j=W[i];j<=MW;++j) {
                    dp[p][j] = std::max(dp[!p][j], dp[!p][j-W[i]] + P[i]);
                }
            }
            
            sum += dp[N&1][MW];
        }
        
        std::cout << sum << std::endl;
    }
    return 0;
}
