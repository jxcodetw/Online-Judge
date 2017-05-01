#include <cstdio>
#include <cstring>

int var[10];
char buf[1024], query[10];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, Q, p, t = 0;
    while(scanf("%d", &N) == 1 && N != 0) {
        printf("S-Tree #%d:\n", ++t);
        p = 1 << N;
        for(int i=0;i<N;++i) {
            scanf("%s", buf);
            var[i] = buf[1]-'1';
        }
        scanf("%s", buf);
        scanf("%d", &Q);
        while(Q--) {
            scanf("%s", query);
            int idx = 1;
            for(int i=0;i<N;++i) {
                idx = idx * 2 + query[var[i]] - '0';
            }
            putchar(buf[idx-p]);
        }
        putchar('\n');
        putchar('\n');
    }
    return 0;
}

