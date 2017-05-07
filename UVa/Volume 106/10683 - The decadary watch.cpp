#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    long long h, m, s, c, sum;
    while(scanf("%2lld%2lld%2lld%2lld", &h, &m, &s, &c) == 4) {
        sum = c*10+s*1000+m*60000+h*3600000;
        h = sum/8640000;
        sum %= 8640000;
        m = sum/86400;
        sum %= 86400;
        s = sum/864;
        sum %= 864;
        c = sum*100/864;
        printf("%lld%02lld%02lld%02lld\n", h, m, s, c);
    }
    return 0;
}
