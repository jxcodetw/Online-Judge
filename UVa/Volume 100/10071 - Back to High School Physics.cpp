#include <cstdio>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int v, t;
    while(scanf("%d%d", &v, &t) == 2) {
        printf("%d\n", 2 * v * t);
    }
    return 0;
}
