#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int K, N, M, x, y;
    while(std::cin >> K && K != 0) {
        std::cin >> N >> M;
        for(int i=0;i<K;++i) {
            std::cin >> x >> y;
            if (x == N || y == M) {
                std::cout << "divisa";
            } else {
                std::cout << ((y>M)?'N':'S');
                std::cout << ((x>N)?'E':'O');
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

