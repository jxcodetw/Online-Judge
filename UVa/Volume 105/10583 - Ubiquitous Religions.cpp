#include <iostream>
#include <cmath>
#include <algorithm>

int group;
int p[50010], r[50010];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        group -= 1;
        if (r[pa] > r[pb]) {
            r[pa] += r[pb];
            p[pb] = pa;
        } else {
            r[pb] += r[pa];
            p[pa] = pb;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, M, a, b, t=1;
    while(std::cin >> N >> M && !(N==0&&M==0)) {
        for(int i=1;i<=N;++i) {
            p[i] = i;
            r[i] = 1;
        }
        group = N;
        for(int i=0;i<M;++i) {
            std::cin >> a >> b;
            _union(a, b);
        }
        std::cout << "Case " << t++ << ": ";
        std::cout << group << std::endl;
    }
    return 0;
}
