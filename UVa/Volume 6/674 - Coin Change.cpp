#include <iostream>

long long int dp[30010];
const long long int val[] = {1, 5, 10, 25, 50};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    dp[0] = 1;
    for(int i=0;i<(sizeof(val)/sizeof(val[0]));++i) {
        long long int v = val[i];
        for(long long int j=v;j<=7489;++j) {
            dp[j] += dp[j-v];
        }
    }
    
    int N;
    while(std::cin >> N) {
        std::cout << dp[N] << std::endl;
    }
    return 0;
}
