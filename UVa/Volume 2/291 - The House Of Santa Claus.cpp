#include <iostream>
#include <cstring>
#include <vector>

std::vector<int> adjList[6];
std::vector<int> path;
bool vis[10][10];

void backtrack(int u) {
    if (path.size() == 8) {
        std::cout << 1;
        for(auto v : path) {
            std::cout << v;
        }
        std::cout << std::endl;
    } else {
        for(auto v : adjList[u]) {
            if (!vis[u][v]) {
                vis[u][v] = vis[v][u] = true;
                path.push_back(v);
                backtrack(v);
                path.pop_back();
                vis[u][v] = vis[v][u] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    memset(vis, 0, sizeof(vis));
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(5);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[2].push_back(5);
    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(4);
    adjList[3].push_back(5);
    adjList[4].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(1);
    adjList[5].push_back(2);
    adjList[5].push_back(3);
    adjList[5].push_back(4);

    path.clear();
    backtrack(1);
    
    return 0;
}
