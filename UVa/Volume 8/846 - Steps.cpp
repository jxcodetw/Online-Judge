#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, x, y, len;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &x, &y);
        len = y-x-1;
        if (len == -1) {
            puts("0");
        } else {
            int r = (int)floor(sqrt(len));
            int step = 2*r;
            if (len >= r*(r+1)) {
                step += 1;
            }
            printf("%d\n", step);            
        }

    }
    return 0;
}

