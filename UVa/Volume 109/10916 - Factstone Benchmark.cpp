#include <cstdio>
#include <cmath>

int ans[30];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int p = 2, n = 0;
    double dig = 0, next = log2(1);
    for(int i=0;i<21;++i) {
        p *= 2;
        while((int)ceil(dig + next) <= p) {
            dig += next;
            next = log2(++n);
        }
        ans[i] = n-1;
    }
    
    int N;
    while(scanf("%d", &N) == 1 && N != 0) {
        int y = (N-1960) / 10;
        printf("%d\n", ans[y]);
    }
    return 0;
}
