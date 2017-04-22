#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, n;
    scanf("%d", &N);
    bool first = true;
    while(N--) {
        if (first) {
            first = false;
        } else {
            putchar('\n');
        }
        scanf("%d", &n);
        if (n == 0) {
            puts("3");
            continue;
        } else if (n < 0) {
            n = -n;
        }
        
        int sum = 0, i = 0;
        while(sum < n) {
            sum += ++i;
        }
        int bit = (n^sum)&1;
        bit = bit|bit<<1;
        i += (1<<(i&1))&bit;
        
        printf("%d\n", i);
    }
    return 0;
}
