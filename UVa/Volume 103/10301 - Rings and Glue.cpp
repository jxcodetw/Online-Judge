#include <iostream>
#include <cmath>
#include <algorithm>

double x[110], y[110], d[110];

int p[110], r[110];
int max;

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        if (r[pa] < r[pb]) {
            std::swap(pa, pb);
        }
        r[pa] += r[pb];
        p[pb] = pa;
        max = std::max(max, r[pa]);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    while(std::cin >> N && (N!=-1)) {
        for(int i=0;i<N;++i) {
            p[i] = i;
            r[i] = 1;
        }
        max = N>0?1:0;
        
        for(int i=0;i<N;++i) {
            std::cin >> x[i] >> y[i] >> d[i];
            for(int j=0;j<i;++j) {
                double dis = hypot(x[i]-x[j], y[i]-y[j]);
                if (fabs(d[i]-d[j]) < dis && dis < d[i]+d[j]) {
                    _union(i, j);
                }
            }
        }
        
        std::cout << "The largest component contains " << max << " ring"
        << (max==1?"":"s") << "." << std::endl;
    }
    return 0;
}
