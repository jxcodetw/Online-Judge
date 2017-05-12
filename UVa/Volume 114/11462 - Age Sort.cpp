#include <cstdio>
#include <cstring>

int cnt[110];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, n;
    while(scanf("%d", &N) && N!=0) {
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<N;++i) {
            scanf("%d", &n);
            cnt[n] += 1;
        }
        bool first = true;
        for(int i=0;i<110;++i) {
            for(int j=0;j<cnt[i];++j) {
                if (first) {
                    first = false;
                } else {
                    putchar(' ');
                }
                printf("%d", i);
            }
        }
        putchar('\n');
    }
    return 0;
}
