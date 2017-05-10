#include <iostream>
#include <algorithm>
#include <cstring>

bool dp[210][30];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, M, C, K;
    std::cin >> N;
    while(N--) {
        
        memset(dp, 0, sizeof(dp));
        std::cin >> M >> C;
        
        std::cin >> K;
        for(int i=0;i<K;++i) {
            int n;
            std::cin >> n;
            if (n <= M) {
                dp[n][1] = true;
            }
        }
        for(int i=1;i<C;++i) {
            std::cin >> K;
            for(int j=0;j<K;++j) {
                int k;
                std::cin >> k;
                for(int p=0;k<=M;++k,++p) {
                    if (dp[p][i]) {
                        dp[k][i+1] = true;
                    }
                }
            }
        }
        int ans = M;
        while(ans >= 0 && dp[ans][C] == false) {
            ans -=1 ;
        }
        if (ans == -1) {
            std::cout << "no solution" << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
