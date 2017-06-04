#include <iostream>
#include <cstdio>

long long int dp[30010];
const long long int val[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    dp[0] = 1;
    for(int i=0;i<(sizeof(val)/sizeof(val[0]));++i) {
        long long int v = val[i];
        for(long long int j=v;j<=30000;j+=5) {
            dp[j] += dp[j-v];
        }
    }
    
    int N1, N2;
    while(scanf("%d.%d", &N1, &N2) == 2 && !(N1==0&&N2==0)) {
        printf("%3d.%02d%17lld\n", N1, N2, dp[N1*100+N2]);
    }
    return 0;
}
