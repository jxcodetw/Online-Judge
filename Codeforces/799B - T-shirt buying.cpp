#include <iostream>
#include <vector>
#include <queue>

struct Tsh {
    int p, a, b;
    bool v;
};

struct cmp {
    bool operator()(const Tsh *a, const Tsh *b) {
        return a->p > b->p;
    }
};

Tsh T[200010];
std::priority_queue<Tsh*, std::vector<Tsh*>, cmp> PQ[4];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, M, c, c1, c2;
    std::cin >> N;
    for(int i=0;i<N;++i) {std::cin >> T[i].p;}
    for(int i=0;i<N;++i) {std::cin >> T[i].a;}
    for(int i=0;i<N;++i) {std::cin >> T[i].b;}
    for(int i=0;i<N;++i) {
        c1 = T[i].a;
        c2 = T[i].b;
        PQ[c1].push({&T[i]});
        if (c1 != c2) {
            PQ[c2].push({&T[i]});
        }
    }
    std::cin >> M;
    for(int i=0;i<M;++i) {
        if (i) {std::cout << ' ';}
        std::cin >> c;
        int p = -1;
        while(!PQ[c].empty()) {
            Tsh* t = PQ[c].top();PQ[c].pop();
            if (!t->v) {
                t->v = true;
                p = t->p;
                break;
            }
        }
        std::cout << p;
    }
    std::cout << std::endl;
    return 0;
}
