#include <iostream>
#include <algorithm>
#include <queue>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int C, L, l, M;
    std::cin >> C;
    while(C--) {
        std::cin >> L >> M;
        L *= 100;
        std::queue<int> Q[2];
        std::string str;
        for(int i=0;i<M;++i) {
            std::cin >> l >> str;
            Q[(str == "left")?0:1].push(l);
        }
        
        int side = 0, cnt = 0;
        while(!(Q[0].empty()&&Q[1].empty())) {
            cnt += 1;
            for(int load=0;!Q[side].empty()&&load+Q[side].front()<=L;++load) {
                load += Q[side].front();
                Q[side].pop();
            }
            side = !side;
        }
        
        std::cout << cnt << std::endl;
    }
    return 0;
}
