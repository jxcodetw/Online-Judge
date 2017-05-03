#include <cstdio>
#include <cstring>

long long dp[60][60][60];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, N;
    double A0, Ak, An1, sum;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lf%lf", &N, &A0, &An1);
        sum = 0;
        for(int i=1, j=N;i<=N;++i, --j) {
            scanf("%lf", &Ak);
            sum += Ak * j;
        }
        printf("%.2lf\n", (N*A0+An1-2*sum)/(N+1));
        if (T) {putchar('\n');}
    }
    return 0;
}

