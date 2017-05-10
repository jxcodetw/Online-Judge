#include <iostream>
#include <algorithm>
#include <cstring>

int M[1025][1025];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, D, N, x = 0, y = 0, p, mx, my;
    std::cin >> T;
    while(T--) {
        memset(M, 0, sizeof(M));
        std::cin >> D >> N;
        for(int i=0;i<N;++i) {
            std::cin >> x >> y >> p;
            mx = std::min(x+D, 1024) + 1;
            my = std::min(y+D, 1024) + 1;
            for(int j=std::max(x-D, 0); j<mx;++j) {
                for(int k=std::max(y-D, 0); k<my;++k) {
                    M[j][k] += p;
                }
            }
        }
        
        int max = -1;
        for(int i=0;i<1025;++i) {
            for(int j=0;j<1025;++j) {
                if (M[i][j] > max) {
                    max = M[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        std::cout << x << ' ' << y << ' ' << max << std::endl;
    }
    return 0;
}

