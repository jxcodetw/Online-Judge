#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int N, H, A, T;
    std::cin >> T;
    while(T--) {
        std::cin >> N >> H;
        A = N-H;
        std::string ans = "";
        for(int i=0;i<A;++i) {
            ans += '0';
        }
        for(int i=0;i<H;++i) {
            ans += '1';
        }
        do {
            std::cout << ans << std::endl;
        } while(std::next_permutation(ans.begin(), ans.end()));
        if (T) {std::cout << std::endl;}
    }
    return 0;
}
