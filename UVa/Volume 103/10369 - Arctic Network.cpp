#include <iostream>
#include <cmath>
#include <algorithm>

struct Edge {
    int a, b;
    double w;
    
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
} edge[500*500+10];

double x[510], y[510];

int p[510], r[510];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

bool _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        if (r[pa] > r[pb]) {
            r[pa] += r[pb];
            p[pb] = pa;
        } else {
            r[pb] += r[pa];
            p[pa] = pb;
        }
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cout.precision(2);
    
    int N, S, P, m;
    double dx, dy;
    std::cin >> N;
    while(N--) {
        std::cin >> S >> P;
        for(int i=0;i<P;++i) {
            p[i] = i;
            r[i] = 1;
        }
        m = 0;
        for(int i=0;i<P;++i) {
            std::cin >> x[i] >> y[i];
            for(int j=0;j<i;++j) {
                dx = x[i] - x[j];
                dy = y[i] - y[j];
                edge[m].a = i;
                edge[m].b = j;
                edge[m].w = dx*dx+dy*dy;
                m += 1;
            }
        }
        std::sort(edge, edge+m);
        
        int cnt = 0;
        for(int i=0;i<m;++i) {
            if (_union(edge[i].a, edge[i].b)) {
                cnt += 1;
                if (cnt == P-S) {
                    std::cout << std::fixed << sqrt(edge[i].w) << std::endl;
                }
            }
            
        }
    }
    return 0;
}
