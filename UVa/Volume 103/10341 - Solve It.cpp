#include <cstdio>
#include <cmath>

double p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) == 6) {
        double l = 0, r = 1, x = 0;
        for(int i=0;i<1000;++i) {
            x = (l+r) / 2;
            if (f(x) > 0) {
                l = x;
            } else {
                r = x;
            }
        }
        
        if (fabs(f(x)) < 1e-10) {
            printf("%.4lf\n", x);
        } else {
            puts("No solution");
        }
    }
    return 0;
}

