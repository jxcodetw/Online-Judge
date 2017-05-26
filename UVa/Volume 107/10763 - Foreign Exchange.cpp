#include <iostream>
#include <algorithm>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, a, b, c;
    while(std::cin >> N && N != 0) {
        std::map<int, std::map<int, int>> M;
        while(N--) {
            std::cin >> a >> b;
            c = 1;
            if (a > b) {
                c = -1;
                std::swap(a, b);
            }
            M[a][b] += c;
        }
        bool valid = true;
        for(auto e1 : M) {
            for(auto e2 : e1.second) {
                if (e2.second != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                break;
            }
        }
        
        if (valid) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
