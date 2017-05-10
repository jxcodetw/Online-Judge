#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

int M, W;
int minR[110], R[110][110], P[110];
bool vis[110];

int bfs() {
    memset(P, 0, sizeof(P));
    memset(vis, 0, sizeof(vis));
    std::queue<int> Q;
    Q.push(1);
    vis[1] = true;
    minR[1] = 1e9;
    
    while(!Q.empty()) {
        int u = Q.front();Q.pop();
        if (u == M) {
            return minR[u];
        }
        for(int v=0;v<110;++v) {
            if (!vis[v] && R[u][v] > 0) {
                vis[v] = true;
                P[v] = u;
                minR[v] = std::min(minR[u], R[u][v]);
                Q.push(v);
            }
        }
    }
    return 0;
}

int maxflow() {
    int f, mf = 0;
    while((f = bfs() != 0)) {
        mf += f;
        for(int v=M,p;v!=1;v=p) {
            p = P[v];
            R[p][v] -= f;
            R[v][p] += f;
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
