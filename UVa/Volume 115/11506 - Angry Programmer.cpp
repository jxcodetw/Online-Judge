#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>

int M, W;
int R[110][110], level[110], iter[110];

bool bfs() {
    memset(level, -1, sizeof(level));
    std::queue<int> Q;
    Q.push(1);
    level[1] = 1;
    
    while(!Q.empty()) {
        int u = Q.front();Q.pop();
        for(int v=0;v<110;++v) {
            if (R[u][v] > 0 && level[v] == -1) {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
    return (level[M] != -1);
}

int dfs(int u, int min) {
    if (u == M) {
        return min;
    } else {
        for(int &v=iter[u];v<110;++v) {
            if (R[u][v] > 0 && level[u]+1 == level[v]) {
                int f = dfs(v, std::min(R[u][v], min));
                if (f > 0) {
                    R[u][v] -= f;
                    R[v][u] += f;
                    return f;
                }
            }
        }
    }
    return 0;
}

int maxflow() {
    int mf = 0;
    while(bfs()) {
        int f;
        memset(iter, 0, sizeof(iter));
        while((f = dfs(1, std::numeric_limits<int>::max())) > 0) {
            mf += f;
        }
    }
    return mf;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    while(std::cin >> M >> W && !(M==0&&W==0)) {
        memset(R, 0, sizeof(R));
        
        for(int i=2;i<M;++i) {
            int m, c;
            std::cin >> m >> c;
            R[m][m+50] = c;
        }
        
        for(int i=0;i<W;++i) {
            int j, k, d;
            std::cin >> j >> k >> d;
            if (j > k) {std::swap(j, k);}
            R[j+(j==1?0:50)][k] = d;
            R[k+(k==M?0:50)][j] = d;
        }
        
        std::cout << maxflow() << std::endl;
    }
    return 0;
}
