#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int n;
    while(std::cin >> n) {
        std::cout << n + n/2 << std::endl;
    }
    
    return 0;
}

