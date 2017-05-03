#include <cstdio>
#include <cstring>

const int MAX = 100+10;
int T1[MAX], T2[MAX];
int dp[MAX][MAX];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N1, N2, t = 1;
    while(scanf("%d%d", &N1, &N2) == 2 && (N1!=0&&N2!=0)) {
        printf("Twin Towers #%d\n", t++);
        for(int i=1;i<=N1;++i) {
            scanf("%d", &T1[i]);
        }
        for(int i=1;i<=N2;++i) {
            scanf("%d", &T2[i]);
        }
        memset(dp, 0, sizeof(dp));
        
        for(int i=1;i<=N1;++i) {
            for(int j=1;j<=N2;++j) {
                if (T1[i] == T2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("Number of Tiles : %d\n\n", dp[N1][N2]);
    }
    return 0;
}

