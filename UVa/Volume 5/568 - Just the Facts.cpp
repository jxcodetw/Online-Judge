#include <cstdio>

int T[10000+10];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    T[0] = 1;
    for(int i=1;i<=10000;++i) {
        T[i] = T[i-1] * i;
        while(T[i] % 10 == 0) {
            T[i] /= 10;
        }
        T[i] %= 100000;
    }
    
    int N;
    while(scanf("%d", &N) == 1) {
        printf("%5d -> %d\n", N, T[N] % 10);
    }
    return 0;
}
