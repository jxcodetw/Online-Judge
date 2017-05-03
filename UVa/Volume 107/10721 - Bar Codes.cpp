#include <cstdio>
#include <cstring>

long long dp[60][60][60];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, k, m;
    
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<60;++i) {dp[0][0][i] = 1;}
    for(m=1;m<60;++m) {
        for(k=1;k<60;++k) {
            for(n=1;n<60;++n) {
                for(int l=1;l<=m&&l<=n;++l) {
                    dp[n][k][m] += dp[n-l][k-1][m];
                }
            }
        }
    }
    
    while(scanf("%d%d%d", &n, &k, &m) == 3) {
        printf("%lld\n", dp[n][k][m]);
    }
    return 0;
}

