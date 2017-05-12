#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, T, K, D;
    while(std::cin >> N >> T >> K >> D) {
        
        // 4 2 1 4
        int left = N-(D/T)*K;
        if (left>K) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
