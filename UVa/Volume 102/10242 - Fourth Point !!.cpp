#include <cstdio>
#include <climits>

void printForth(double x, double y, double x1, double y1, double x2, double y2) {
    printf("%.3lf %.3lf\n", x+x1+x2, y+y1+y2);
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8) {
        if (x1 == x3 && y1 == y3) {
            printForth(x1, y1, x2-x1, y2-y1, x4-x1, y4-y1);
        } else if (x1 == x4 && y1 == y4) {
            printForth(x1, y1, x2-x1, y2-y1, x3-x1, y3-y1);
        } else if (x2 == x3 && y2 == y3) {
            printForth(x2, y2, x1-x2, y1-y2, x4-x2, y4-y2);
        } else if (x2 == x4 && y2 == y4) {
            printForth(x2, y2, x1-x2, y1-y2, x3-x2, y3-y2);
        }
    }
    return 0;
}

