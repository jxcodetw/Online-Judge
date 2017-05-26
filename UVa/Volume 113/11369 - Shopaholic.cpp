#include <iostream>
#include <algorithm>

int p[20010];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, N;
    std::cin >> T;
    while(T--) {
        std::cin >> N;
        for(int i=1;i<=N;++i) {
            std::cin >> p[i];
        }
        std::sort(p+1, p+N+1, std::greater<int>());
        
        int ans = 0;
        for(int i=3;i<=N;i+=3) {
            ans += p[i];
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}
