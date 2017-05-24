#include <iostream>
#include <cmath>
#include <algorithm>

int p[20010], r[20010];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _merge(int pa, int pb) {
    if (pa != pb) {
        if (r[pa] < r[pb]) {
            std::swap(pa, pb);
        }
        r[pa] += r[pb];
        p[pb] = pa;
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, px, py ,ex ,ey;
    std::cin >> N;
    for(int i=0;i<2*N;++i) {
        p[i] = i;
        r[i] = 1;
    }
    int c, x, y;
    while(std::cin>>c>>x>>y && !(c==0&&x==0&&y==0)) {
        px = _find(x); ex = _find(x+N);
        py = _find(y); ey = _find(y+N);
        switch(c) {
            case 1:
                if (px == ey) {
                    std::cout << -1 << std::endl;
                } else {
                    _merge(px, py);
                    _merge(ex, ey);
                }
                break;
            case 2:
                if (px == py) {
                    std::cout << -1 << std::endl;
                } else {
                    _merge(px, ey);
                    _merge(ex, py);
                }
                break;
            case 3:
                std::cout << ((px == py)?1:0) << std::endl;
                break;
            case 4:
                std::cout << ((px == ey)?1:0) << std::endl;
                break;
        }
    }
    return 0;
}
