#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>

struct Node {
    bool vis;
};

Node* findNode(std::map<int, Node*> &M, int n) {
    auto iter = M.find(n);
    Node* node;
    if (iter == M.end()) {
        node = new Node();
        M.insert(std::make_pair(n, node));
    } else {
        node = iter->second;
    }
    return node;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, a, b, t = 1;
    while(std::cin >> N && N != 0) {
        std::map<Node*, std::vector<Node*>> adjList;
        std::map<int, Node*> M;
        for(int i=0;i<N;++i) {
            std::cin >> a >> b;
            Node *na = findNode(M, a);
            Node *nb = findNode(M, b);
            adjList[na].push_back(nb);
            adjList[nb].push_back(na);
        }
        
        while(std::cin >> a >> b && !(a==0&&b==0)) {
            // a = node
            // b = ttl
            for(auto e : M) {e.second->vis = false;}
            std::set<int> vis;
            std::queue<Node*> Q;
            Node *na = findNode(M, a);
            na->vis = true;
            Q.push(na);
            
            int cnt = 0, ttl = b;
            if (adjList.find(na) != adjList.end()) { // avoid adding node to adjList
                // bfs
                while(!Q.empty() && b-- >= 0) {
                    int len = (int)Q.size();
                    cnt += len;
                    for(int i=0;i<len;++i) {
                        Node *u = Q.front();Q.pop();
                        for(auto v : adjList[u]) {
                            if (!v->vis) {
                                v->vis = true;
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
        for(auto e : M) {delete e.second;}
    }
    return 0;
}
