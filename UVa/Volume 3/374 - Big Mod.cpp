#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    long long int  B,P,M;
    while(std::cin>>B>>P>>M) {
        long long int r = 1;
        B %= M;
        while(P) {
            if (P&1) {
                r = (r * B) % M;
            }
            B = (B * B) % M;
            P >>= 1;
        }
        std::cout << r << std::endl;
    }
    return 0;
}
