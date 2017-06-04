#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int N, D, I;
    std::cin >> N;
    while(N--) {
        std::cin >> D >> I;
        int ans = 1;
        while(--D) {
            // if I % 2 == 0 go right else go left
            // go left ans = ans * 2;
            // go right ans = ans * 2 + 1;
            ans = (ans<<1)|((~I)&1);
            I = (I+1)>>1; // I=(I+1)/2
        }
        std::cout << ans << std::endl;
    }
    std::cin >> N; // absorb -1
    return 0;
}
