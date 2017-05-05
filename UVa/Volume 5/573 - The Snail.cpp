#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    double H, U, D, F;
    while(scanf("%lf%lf%lf%lf", &H, &U, &D, &F) == 4 && (H!=0)) {
        F = U * F / 100;
        double climb = 0;
        int day = 0;
        bool succ = false;
        while(true) {
            day += 1;
            climb += U;
            if (climb > H) {
                succ = true;
                break;
            }
            U -= F;
            if (U < 0) {
                U = 0;
            }
            
            climb -= D;
            if (climb < 0) {
                succ = false;
                break;
            }
        }
        if (succ) {
            printf("success on day %d\n", day);
        } else {
            printf("failure on day %d\n", day);
        }
    }
    return 0;
}

