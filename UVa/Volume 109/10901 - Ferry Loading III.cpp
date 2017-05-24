#include <iostream>
#include <algorithm>
#include <queue>

struct Car {
    int start, end;
} car[10010];

bool next(std::queue<Car*> &Q, int t) {
    return (!Q.empty() && Q.front()->start <= t);
}

int nearest(std::queue<Car*> &Q) {
    if (!Q.empty()) {
        return Q.front()->start;
    }
    return 1e9;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int C, N, T, M;
    std::cin >> C;
    while(C--) {
        std::cin >> N >> T >> M;
        std::queue<Car*> Q[2];
        std::string str;
        for(int i=0;i<M;++i) {
            std::cin >> car[i].start >> str;
            Q[(str=="left")?0:1].push(&car[i]);
        }
        
        int t=0, side=0;
        while(!(Q[0].empty() && Q[1].empty())) {
            if (next(Q[side],t) || next(Q[!side], t)) {
                for(int load=0;load<N && next(Q[side],t);++load) {
                    Q[side].front()->end = t + T;
                    Q[side].pop();
                }
                t += T;
                side = !side;
            } else {
                int here = nearest(Q[ side]);
                int there = nearest(Q[!side]);
                t = std::min(here, there);
                if (there < here) {
                    t += T;
                    side = !side;
                }
            }
        }
        
        for(int i=0;i<M;++i) {
            std::cout << car[i].end << std::endl;
        }
        if (C) {std::cout << std::endl;}
    }
    return 0;
}
