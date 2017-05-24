#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

struct Project {
    std::string name;
    std::size_t num;
    
    bool operator<(const Project &rhs) const {
        return std::tie(num, rhs.name) > std::tie(rhs.num, name);
    }
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string str, proj;
    std::map<std::string, std::set<std::string>> M;
    std::vector<std::string> Lines;
    std::set<std::string> S, rep, S2;
    while(true) {
        std::getline(std::cin, str);
        if (str[0] == '0') {
            break;
        } else if (str[0] == '1') {
            for(auto l : Lines) {
                if (l[0] >= 'A' && l[0] <= 'Z') {
                    proj = l;
                    M[proj].insert("");
                } else {
                    if (rep.find(l) == rep.end()) {
                        M[proj].insert(l);
                    }
                }
            }
            std::vector<Project> P;
            for(auto e : M) {
                P.push_back({e.first, e.second.size()});
            }
            std::sort(P.begin(), P.end());
            M.clear();
            S.clear();
            Lines.clear();
            for(auto p : P) {
                std::cout << p.name << ' ' << p.num-1<< std::endl;
            }
        } else if (str[0] >= 'A' && str[0] <= 'Z') {
            Lines.push_back(str);
            for(auto s : S2) {
                S.insert(s);
            }
            S2.clear();
        } else if (str[0] >= 'a' && str[0] <= 'z') {
            Lines.push_back(str);
            if (S.find(str) == S.end()) {
                S2.insert(str);
            } else {
                rep.insert(str);
            }
        }
        
    }
    
    return 0;
}
