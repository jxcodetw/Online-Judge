#include <cstdio>
#include <cmath>

const double PI = acos(-1);

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int T;
    double B, H, r, factor, sum;
    scanf("%d", &T);
    while(T--) {
        scanf("%lf%lf", &B, &H);
        r = H * B / (2*sqrt(H*H+B*B/4)+B);
        factor = (H-2*r)/H;
        sum = 0;
        while(r > 0.000001) {
            sum += r;
            r *= factor;
        }
        printf("%13.6lf\n",2.0*sum*PI);
        if (T) {putchar('\n');}
    }
    return 0;
}
