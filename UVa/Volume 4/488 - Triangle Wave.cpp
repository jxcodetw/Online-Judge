#include <cstdio>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, A, F;
    while(scanf("%d", &N) == 1) {
        while(N--) {
            scanf("%d%d", &A, &F);
            while(F--) {
                for(int i=1;i<=A;++i) {
                    for(int j=0;j<i;++j) {
                        printf("%d", i);
                    }
                    putchar('\n');
                }
                
                for(int i=A-1;i>=1;--i) {
                    for(int j=0;j<i;++j) {
                        printf("%d", i);
                    }
                    putchar('\n');
                }
                
                if (F > 0 || N > 0) {
                    putchar('\n');
                }
            }
        }
    }
    
    return 0;
}
