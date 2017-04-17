#include <cstdio>
#include <cstdlib>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long int a, b;
    while(scanf("%lld%lld", &a, &b) == 2) {
        printf("%lld\n", (a>b)?a-b:b-a);
    }
    return 0;
}
