#include <cstdio>
int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    while(scanf("%d%d", &a, &b) == 2) {
        printf("%d\n", a*b-1);
    }
    return 0;
}
