#include <cstdio>

int gcd(int a, int b) {
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    while(scanf("%d%d", &a, &b) == 2) {
        printf("%10d%10d", a, b);
        if (gcd(a, b) == 1) {
            puts("    Good Choice");
        } else {
            puts("    Bad Choice");
        }
        putchar('\n');
    }
    return 0;
}
