#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N, n, a, b, c, d;
    scanf("%d", &N);
    for(int t=1;t<=N;++t) {
        scanf("%d", &n);
        int i =2;
        for(i=2;;++i) {
            if (n % i == 0) {
                a = i;
                b = n / i;
                break;
            }
        }
        for(++i;;++i) {
            if (n % i == 0) {
                c = i;
                d = n / i;
                break;
            }
        }
        
        printf("Case #%d: %d = %d * %d = %d * %d\n", t, n, a, b, c, d);
    }
    
    return 0;
}
