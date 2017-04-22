#include <cstdio>
#include <climits>
#include <cmath>

const int MAX = 5000+10;
int tree[MAX][4];
int histogram[10];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int t = 0, x, y, z, d, dx, dy, dz;
    for(int i=0;i<MAX;++i) {
        tree[i][3] = INT_MAX;
    }
    while(scanf("%d%d%d", &x, &y, &z) == 3 && !(x==0&&y==0&&z==0)) {
        tree[t][0] = x;
        tree[t][1] = y;
        tree[t][2] = z;
        for(int i=0;i<t;++i) {
            dx = tree[i][0] - tree[t][0];
            dy = tree[i][1] - tree[t][1];
            dz = tree[i][2] - tree[t][2];
            d = (int)floor(sqrt(dx*dx+dy*dy+dz*dz));
            if (d < tree[t][3]) {tree[t][3] = d;}
            if (d < tree[i][3]) {tree[i][3] = d;}
        }
        t += 1;
    }
    for(int i=0;i<t;++i) {
        if (tree[i][3] >= 0 && tree[i][3] <= 9) {
            histogram[tree[i][3]] += 1;
        }
    }
    for(int i=0;i<10;++i) {
        printf("%4d", histogram[i]);
    }
    putchar('\n');
    return 0;
}
