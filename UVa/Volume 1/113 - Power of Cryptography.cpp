#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    double n, p;
    while(~scanf("%lf%lf", &n, &p)) {
        printf("%.0lf\n", pow(p, 1/n));
    }
    
    return 0;
}
