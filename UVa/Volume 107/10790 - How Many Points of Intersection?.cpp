#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    long long a, b;
    int t = 1;
    while(scanf("%lld%lld", &a, &b) && (a!=0&&b!=0)) {
        printf("Case %d: %lld\n", t++, a*(a-1)*b*(b-1) / 4);
    }
    return 0;
}

