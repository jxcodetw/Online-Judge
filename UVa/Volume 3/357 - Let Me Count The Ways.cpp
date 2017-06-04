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
        for(long long int j=v;j<=30000;++j) {
            dp[j] += dp[j-v];
        }
    }
    
    int N;
    while(std::cin >> N) {
        if (dp[N] == 1) {
            std::cout << "There is only " << dp[N] << " way";
        } else {
            std::cout << "There are " << dp[N] << " ways";
        }
        std::cout << " to produce " << N << " cents change." << std::endl;
    }
    return 0;
}
