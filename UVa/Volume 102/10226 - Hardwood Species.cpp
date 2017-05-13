#include <iostream>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cout.precision(4);
    
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::string line;
    std::getline(std::cin, line);
    while(N--) {
        std::map<std::string, double> M;
        double cnt = 0;
        while(std::getline(std::cin, line) && line != "") {
            auto iter = M.find(line);
            if (iter == M.end()) {
                M.insert(std::make_pair(line, 1));
            } else {
                iter->second += 1;
            }
            cnt += 1;
        }
        for(auto &ent : M) {
            std::cout << ent.first << ' ' << std::fixed << ent.second * 100 / cnt << std::endl;
        }
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
