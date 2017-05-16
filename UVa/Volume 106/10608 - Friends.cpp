#include <iostream>
#include <algorithm>

int max;
int p[30010], r[30010];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        // make sure pa has more member
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
    
    int N, M, T, a, b;
    std::cin >> T;
    while(T--) {
        std::cin >> N >> M;
        max = 1;
        for(int i=1;i<=N;++i) {
            p[i] = i;
            r[i] = 1;
        }
        while(M--) {
            std::cin >> a >> b;
            _union(a, b);
        }
        std::cout << max << std::endl;
    }
    return 0;
}
