#include <iostream>
#include <algorithm>
#include <cstring>

int model[30];
int dp[210][30];

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
        // dp[M][C] // ans
        std::cin >> K;
        for(int i=0;i<K;++i) {
            int n;
            std::cin >> n;
            for(int j=n;j<=M;++j) {
                dp[j][1] = std::max(dp[j][1], n);
            }
        }
        for(int i=1;i<C;++i) {
            std::cin >> K;
            for(int j=0;j<K;++j) {
                std::cin >> model[j];
            }
            
            for(int j=0;j<=M;++j) {
                for(int k=0;k<K;++k) {
                    int sub = j-model[k];
                    if (sub >= 0 && dp[sub][i] > 0 && dp[sub][i] + model[k] <= M) {
                        dp[j][i+1] = std::max(dp[j][i+1], dp[sub][i] + model[k]);
                    }
                }
            }
        }
        
        if (dp[M][C]) {
            std::cout << dp[M][C] << std::endl;
        } else {
            std::cout << "no solution" << std::endl;
        }
    }
    return 0;
}
