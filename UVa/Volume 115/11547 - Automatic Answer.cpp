#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, n;
    std::cin >> T;
    while(T--) {
        std::cin >> n;
        n = (((n*567)/9+7492)*235)/47-498;
        if (n < 0) {
            n = -n;
        }
        n /= 10;
        std::cout << n % 10 << std::endl;
    }
    
    return 0;
}

