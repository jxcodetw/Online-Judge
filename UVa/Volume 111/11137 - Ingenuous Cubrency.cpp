#include <iostream>

long long int dp[30010];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    dp[0] = 1;
    for(int i=1;i<=21;++i) {
        long long int v = i*i*i;
        for(long long int j=v;j<=10000;++j) {
            dp[j] += dp[j-v];
        }
    }
    
    int N;
    while(std::cin >> N) {
        std::cout << dp[N] << std::endl;
    }
    return 0;
}
