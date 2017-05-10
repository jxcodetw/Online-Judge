#include <iostream>
#include <cstring>

const int MAX = 1026;

int M[MAX][MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, D, N, x = 0, y = 0, p;
    std::cin >> T;
    while(T--) {
        memset(M, 0, sizeof(M));
        std::cin >> D >> N;
        for(int i=0;i<N;++i) {
            std::cin >> x >> y >> p;
            M[x+1][y+1] += p;
        }
        
        for(int i=1;i<MAX;++i) {
            for(int j=1;j<MAX;++j) {
                M[i][j] += M[i-1][j] + M[i][j-1] - M[i-1][j-1];
            }
        }
        
        int max = -1, len = 2*D+1;
        for(int i=len, _i=0;i<MAX;++i, ++_i) {
            for(int j=len, _j=0;j<MAX;++j, ++_j) {
                int num = M[i][j] - M[i][_j] - M[_i][j] + M[_i][_j];
                if (max < num) {
                    max = num;
                    x = _i;
                    y = _j;
                }
            }
        }
        std::cout << x+D << ' ' << y+D << ' ' << max << std::endl;
    }
    return 0;
}
