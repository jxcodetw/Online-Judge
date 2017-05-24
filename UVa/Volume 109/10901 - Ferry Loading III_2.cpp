#include <iostream>
#include <algorithm>
#include <queue>

int car[10010];

int nearest(std::queue<int> &Q) {
    if (!Q.empty()) {
        return car[Q.front()];
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
        std::queue<int> Q[2];
        std::string str;
        for(int i=0;i<M;++i) {
            std::cin >> car[i] >> str;
            Q[(str=="left")?0:1].push(i);
        }
        
        for(int t=0, side=0;!(Q[0].empty() && Q[1].empty());t+=T, side=!side) {
            t = std::max(t, std::min(nearest(Q[side]), nearest(Q[!side])));
            
            for(int load=0;load<N && nearest(Q[side]) <= t;++load) {
                car[Q[side].front()] = t + T;
                Q[side].pop();
            }
        }
        
        for(int i=0;i<M;++i) {
            std::cout << car[i] << std::endl;
        }
        if (C) {std::cout << std::endl;}
    }
    return 0;
}
