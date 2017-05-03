#include <cstdio>
#include <climits>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, n, a;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<n;++i) {
            scanf("%d", &a);
            if (a > max) {
                max = a;
            }
            if (a < min) {
                min = a;
            }
        }
        printf("%d\n", (max-min)*2);
    }
    return 0;
}

