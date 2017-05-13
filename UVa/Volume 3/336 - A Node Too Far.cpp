#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, a, b, t = 1;
    while(std::cin >> N && N != 0) {
        std::map<int, std::vector<int>> adjList;
        for(int i=0;i<N;++i) {
            std::cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        
        while(std::cin >> a >> b && !(a==0&&b==0)) {
            // a = node
            // b = ttl
            std::set<int> vis;
            std::queue<int> Q;
            Q.push(a);
            vis.insert(a);
            
            int cnt = 0, ttl = b;
            if (adjList.find(a) != adjList.end()) { // avoid adding node to adjList
                // bfs
                while(!Q.empty() && b-- >= 0) {
                    int len = (int)Q.size();
                    cnt += len;
                    for(int i=0;i<len;++i) {
                        int u = Q.front();Q.pop();
                        for(auto v : adjList[u]) {
                            if (vis.find(v) == vis.end()) {
                                vis.insert(v);
                                Q.push(v);
                            }
                        }
                    }
                }                
            }
            std::cout << "Case " << t++ << ": "
            << adjList.size() - cnt
            << " nodes not reachable from node " << a
            << " with TTL = " << ttl << "."
            << std::endl;
        }
    }
    return 0;
}
