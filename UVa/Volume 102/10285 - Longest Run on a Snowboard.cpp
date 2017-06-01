#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

struct Node {
    int r, c, v;
    
    bool operator<(const Node &rhs) const {
        return v < rhs.v;
    }
};


int M[110][110], H[110][110];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int N, R, C;
    std::cin >> N;
    std::string name;
    while(N--) {
        std::cin >> name >> R >> C;
        std::cout << name << ": ";
        memset(M, 0, sizeof(M));
        
        std::vector<Node> node;
        for(int i=0;i<R;++i) {
            for(int j=0;j<C;++j) {
                std::cin >> H[i][j];
                node.push_back({i, j, H[i][j]});
            }
        }
        std::sort(node.begin(), node.end());
        
        int max = 0;
        for(auto nd : node) {
            int &m = M[nd.r][nd.c], t;
            if ((t=nd.r-1) >= 0 && nd.v > H[t][nd.c]) {
                m = std::max(m, 1+M[t][nd.c]);
            }
            if ((t=nd.r+1) < R && nd.v > H[t][nd.c]) {
                m = std::max(m, 1+M[t][nd.c]);
            }
            
            if ((t=nd.c-1) >= 0 && nd.v > H[nd.r][t]) {
                m = std::max(m, 1+M[nd.r][t]);
            }
            if ((t=nd.c+1) < C && nd.v > H[nd.r][t]) {
                m = std::max(m, 1+M[nd.r][t]);
            }
            max = std::max(max, m);
        }
        std::cout << max+1 << std::endl;
    }
    return 0;
}
