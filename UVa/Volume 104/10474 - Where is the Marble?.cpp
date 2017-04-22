#include <cstdio>
#include <vector>
#include <algorithm>

const int MAX = 10000+10;
int a[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N, Q, q, t = 0;
    long lb;
    while(scanf("%d%d", &N, &Q) == 2 && (N != 0 && Q != 0)) {
        for(int i=0;i<N;++i) {
            scanf("%d", &a[i]);
        }
        
        std::sort(a, a+N);
        
        printf("CASE# %d:\n", ++t);
        for(int i=0;i<Q;++i) {
            scanf("%d", &q);
            lb = std::lower_bound(a, a+N, q) - a;
            if (a[lb] == q) {
                printf("%d found at %ld\n", q, lb + 1);
            } else {
                printf("%d not found\n", q);
            }
            
        }
    }
    return 0;
}
