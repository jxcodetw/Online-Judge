#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    std::string from, to, str;
    int N;
    while(std::cin >> N && N != 0) {
        std::cin.ignore();
        std::vector<std::pair<std::string, std::string>> M;
        while(N--) {
            std::getline(std::cin, from);
            std::getline(std::cin, to);
            M.push_back(std::make_pair(from, to));
        }
        std::getline(std::cin, str);
        for(auto const &ent : M) {
            size_t pos;
            while((pos = str.find(ent.first)) != std::string::npos) {
                str.replace(pos, ent.first.length(), ent.second);
            }
        }
        std::cout << str << std::endl;
    }
    return 0;
}
