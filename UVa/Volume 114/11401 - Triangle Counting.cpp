#include <cstdio>

const int N = 1000000 + 10;
long long a[N];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    a[3] = 0;
    for(long long i = 4; i < N; i++) {
        a[i] = a[i - 1] + ((i - 1) * (i - 2) / 2 - (i - 1 - i / 2)) / 2;
    }
    int n;
    while(scanf("%d", &n) == 1) {
        if(n < 3) break;
        printf("%lld\n", a[n]);
    }

    return 0;
}

