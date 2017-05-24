#include <iostream>
#include <vector>
#include <queue>
#include <map>

std::map<std::string, int> langM;
int id;
int getID(std::string &s) {
    auto iter = langM.find(s);
    int res;
    if (iter == langM.end()) {
        res = id;
        langM.insert(std::make_pair(s, id++));
    } else {
        res = iter->second;
    }
    return res;
}

struct Edge {
    int to, w, c;
    
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};

std::vector<Edge> adjList[4010];
std::vector<int> dis[26];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int M, s, t;
    std::string startLang, finishLang, I1, I2, P;
    while(std::cin >> M && M != 0) {
        std::cin >> startLang >> finishLang;
        id = 0;
        langM.clear();
        for(int i=0;i<2010;++i) {
            adjList[i].clear();
        }
        
        for(int i=0;i<M;++i) {
            std::cin >> I1 >> I2 >> P;
            int a = getID(I1), b = getID(I2);
            adjList[a].push_back({b, (int)P.length(), P[0]-'a'});
            adjList[b].push_back({a, (int)P.length(), P[0]-'a'});
        }
        s = getID(startLang); t = getID(finishLang);
            
        for(int i=0;i<26;++i) {
            dis[i].resize(langM.size());
            std::fill(dis[i].begin(), dis[i].end(), 1e9);
            dis[i][s] = 0;
        }
        
        std::priority_queue<Edge> PQ;
        PQ.push({s, 0, -1});
        while(!PQ.empty()) {
            Edge path = PQ.top();PQ.pop();
            for(auto v : adjList[path.to]) {
                if (v.c != path.c) {
                    int relax = path.w + v.w;
                    if (relax < dis[v.c][v.to]) {
                        dis[v.c][v.to] = relax;
                        PQ.push({v.to, relax, v.c});
                    }
                }
            }
        }
        
        int ans = 1e9;
        for(int i=0;i<26;++i) {
            if (ans > dis[i][t]) {
                ans = dis[i][t];
            }
        }
        
        if (ans == 1e9) {
            std::cout << "impossivel" << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
