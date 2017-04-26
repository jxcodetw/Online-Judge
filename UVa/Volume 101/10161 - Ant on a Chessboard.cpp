#include <cstdio>

int abs(int n) {
    return n < 0 ? -n : n;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n != 0) {
        int adder, sum = 0, i = 0;
        for(adder = -1; sum < n;++i) {
            adder += 2;
            sum += adder;
        }
        int r = i, c = i;
        int avg = (adder>>1)+1, idx = n-sum+adder, diff = -abs(idx-avg);
        if (i&1) {
            if (idx > avg) {
                c += diff;
            } else if (idx < avg) {
                r += diff;
            }
        } else {
            if (idx > avg) {
                r += diff;
            } else if (idx < avg) {
                c += diff;
            }
        }
        printf("%d %d\n", c, r);
    }
    return 0;
}
