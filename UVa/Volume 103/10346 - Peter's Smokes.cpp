#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, K, ans, butt;
    while(std::cin >> N >> K) {
        ans = N, butt = N;
        while(butt >= K) {
            N = butt / K;
            ans += N;
            butt = N + butt % K;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
