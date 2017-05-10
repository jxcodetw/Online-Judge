#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

int M, W;
int R[110][110], level[110];
bool Added[110][110];
std::vector<int> adjList[110];
std::vector<int>::iterator iter[110];

bool bfs() {
    memset(level, -1, sizeof(level));
    std::queue<int> Q;
    Q.push(1);
    level[1] = 1;
    
    while(!Q.empty()) {
        int u = Q.front();Q.pop();
        for(auto const v : adjList[u]) {
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
        for(auto &e=iter[u];e!=adjList[u].end();++e) {
            int v = *e;
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
        for(int i=0;i<110;++i) {
            iter[i] = adjList[i].begin();
        }
        while((f = dfs(1, std::numeric_limits<int>::max())) > 0) {
            mf += f;
        }
    }
    return mf;
}

void addEdge(int a, int b, int w) {
    R[a][b] = w;
    if (!Added[a][b]) {adjList[a].push_back(b);}
    if (!Added[b][a]) {adjList[b].push_back(a);}
    Added[a][b] = Added[b][a] = true;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    while(std::cin >> M >> W && !(M==0&&W==0)) {
        memset(R, 0, sizeof(R));
        memset(Added, 0, sizeof(Added));
        
        for(int i=0;i<110;++i) {
            adjList[i].clear();
        }
        
        for(int i=2;i<M;++i) {
            int m, c;
            std::cin >> m >> c;
            addEdge(m, m+50, c);
        }
        
        for(int i=0;i<W;++i) {
            int j, k, d;
            std::cin >> j >> k >> d;
            if (j > k) {std::swap(j, k);}
            addEdge(j+(j==1?0:50), k, d);
            addEdge(k+(k==M?0:50), j, d);
        }
        
        std::cout << maxflow() << std::endl;
    }
    return 0;
}
