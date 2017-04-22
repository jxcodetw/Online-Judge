#include <iostream>
#include <sstream>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::string line, country;
    std::map<std::string, int> M;
    while(N--) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> country;
        auto iter = M.find(country);
        if (iter != M.end()) {
            iter->second += 1;
        } else {
            M.insert(std::make_pair(country, 1));
        }
    }
    for(auto iter=M.begin();iter!=M.end();++iter) {
        std::cout << iter->first << ' ' << iter->second << std::endl;
    }
    
    
    return 0;
}
