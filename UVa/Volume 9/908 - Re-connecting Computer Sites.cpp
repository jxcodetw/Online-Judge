#include <iostream>
#include <queue>

int p[1000010], r[1000010];

struct Edge {
    int a, b, w;
    
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};

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
    
    int N, K, a, b, w, ans1, ans2;
    bool first = true;
    while(std::cin >> N) {
        for(int i=1;i<=N;++i) {
            p[i] = i;
            r[i] = 1;
        }
        
        ans1 = 0;
        for(int i=1;i<=N-1;++i) {
            std::cin >> a >> b >> w;
            ans1 += w;
        }
        
        std::priority_queue<Edge> PQ;
        std::cin >> K;
        for(int i=0;i<K;++i) {
            std::cin >> a >> b >> w;
            PQ.push({a, b, w});
        }
        std::cin >> K;
        for(int i=0;i<K;++i) {
            std::cin >> a >> b >> w;
            PQ.push({a, b, w});
        }
        
        //Kruskal
        int selected = 0;
        ans2 = 0;
        while(selected != N-1){
            Edge e = PQ.top();PQ.pop();
            if (_union(e.a, e.b)) {
                ans2 += e.w;
                selected += 1;
            }
        }
        
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
        std::cout << ans1 << std::endl;
        std::cout << ans2 << std::endl;
    }
    return 0;
}
