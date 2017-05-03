#include <iostream>
#include <sstream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int k, q, c;
    std::string line;
    while(std::cin >> k) {
        std::cout << "q(x):";
        std::cin.ignore();
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> q;
        while(ss >> c) {
            std::cout << ' ' << q;;
            q = c+k*q;
        }
        
        std::cout << std::endl << "r = " << q << std::endl << std::endl;
    }
    return 0;
}

