#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T;
    long long a, b, x, y;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &a, &b);
        
        x = (a+b) / 2;
        y = x - b;
        
        if (b > a || (a+b) % 2 == 1) {
            puts("impossible");
        } else {
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}

