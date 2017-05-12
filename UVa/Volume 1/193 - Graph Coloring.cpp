#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<int> adjList[110], black, max;
int N, color[110];

void backtrack(int n) {
    if (n > N) {
        if (black.size() > max.size()) {
            max = black;
        }
    } else {
        bool hasBlack = false;
        for(auto v : adjList[n]) {
            if (color[v] == 1) {
                hasBlack = true;
                break;
            }
        }
        
        if (!hasBlack) {
            color[n] = 1;
            black.push_back(n);
            backtrack(n+1);
            black.pop_back();
        }
        color[n] = 0;
        backtrack(n+1);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int M, a, b, k;
    std::cin >> M;
    while(M--) {
        std::cin >> N >> k;
        for(int i=0;i<110;++i) {
            adjList[i].clear();
        }
        black.clear();
        max.clear();
        std::fill(color, color+110, 0);
        
        while(k--) {
            std::cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        
        backtrack(1);
        
        std::cout << max.size() << std::endl;
        std::cout << max[0];
        for(int i=1;i<max.size();++i) {
            std::cout << ' ' << max[i];
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}
