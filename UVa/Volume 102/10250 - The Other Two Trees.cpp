#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    double ax,ay,cx,cy;
    while(scanf("%lf%lf%lf%lf",&ax,&ay,&cx,&cy) == 4)
    {
        double bx = (cx+ax+cy-ay)/2;
        double by = (cy+ay+ax-cx)/2;
        double dx = (cx+ax+ay-cy)/2;
        double dy = (cy+ay+cx-ax)/2;
        printf("%.10lf %.10lf %.10lf %.10lf\n",bx,by,dx,dy);
        
    }
    return 0;
}
