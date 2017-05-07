#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, a, b;
    std::cin >> T;
    while(T--) {
        std::cin >> a >> b;
        std::cout << (a/3)*(b/3) << std::endl;
    }
    return 0;
}

