#include <cstdio>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N;
    while(scanf("%d", &N) == 1) {
        while(N--) {
            int F, sum = 0;
            scanf("%d", &F);
            while(F--) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                sum += a*c;
            }
            printf("%d\n", sum);
        }
        break;
    }
    return 0;
}
