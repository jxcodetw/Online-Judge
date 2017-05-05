#include <iostream>
#include <cstdio>
#include <cstring>

int A[30];
bool state[30];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, M, C, n, t = 0;
    while(scanf("%d%d%d", &N, &M, &C) == 3 && (N!=0&&M!=0&&C!=0)) {
        printf("Sequence %d\n", ++t);
        memset(state, false, sizeof(state));
        
        bool safe = true;
        int used = 0, max = -1;
        for(int i=1;i<=N;++i) {
            scanf("%d", &A[i]);
        }
        for(int i=1;i<=M;++i) {
            scanf("%d", &n);
            state[n] = !state[n];
            if (state[n]) {
                used += A[n];
                if (used > C) {
                    safe = false;
                }
                if (used > max) {
                    max = used;
                }
            } else {
                used -= A[n];
            }
        }
        
        if (safe) {
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %d amperes.\n", max);
        } else {
            puts("Fuse was blown.");
        }
        putchar('\n');
    }
    return 0;
}

