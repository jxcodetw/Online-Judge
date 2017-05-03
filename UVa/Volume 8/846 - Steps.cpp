#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
//    for(int i=1;i<100;++i) {
//        int r = (int)floor(sqrt(i-1));
//        int step = 2*r;
//        if (i-1 >= r*(r+1)) {
//            step += 1;
//        }
//        printf("%d: %d\n", i, step);
//    }
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

