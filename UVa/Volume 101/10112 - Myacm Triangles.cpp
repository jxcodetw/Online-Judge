#include <cstdio>
#include <cmath>
#include <algorithm>

class Point {
public:
    char label;
    double x;
    double y;
    Point() {}
};

Point pt[20];

double area(const Point &a, const Point &b, const Point &c) {
    return 0.5 * fabs((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x));
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N, x, y;
    char l, ans[4];
    ans[3] = '\0';
    while(scanf("%d\n", &N) == 1 && N != 0) {
        for(int i=0;i<N;++i) {
            scanf("%c%d%d\n", &l, &x, &y);
            pt[i].label = l;
            pt[i].x = (double)x;
            pt[i].y = (double)y;
        }
        
        double max = -1;
        for(int i=0;i<N;++i) {
            for(int j=i+1;j<N;++j) {
                for(int k=j+1;k<N;++k) {
                    double a = area(pt[i], pt[j], pt[k]);
                    bool hasPoint = false;
                    for(int p=0;p<N;++p) {
                        if (p == i || p == j || p == k) {continue;}
                        if (area(pt[i], pt[j], pt[p]) +
                            area(pt[j], pt[k], pt[p]) +
                            area(pt[k], pt[i], pt[p]) == a) {
                            hasPoint = true;
                            break;
                        }
                    }
                    if (hasPoint) {continue;}
                    if (a >= max) {
                        max = a;
                        ans[0] = pt[i].label;
                        ans[1] = pt[j].label;
                        ans[2] = pt[k].label;
                    }
                }
            }
        }
        std::sort(ans, ans+3);
        puts(ans);
    }
    return 0;
}
