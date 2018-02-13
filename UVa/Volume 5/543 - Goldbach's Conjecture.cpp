#include <iostream>
#include <vector>
#include <bitset>

#define MAX 1000010
std::bitset<MAX> P;
std::vector<int> prime;

void build() {
    P.set();
    P.reset(0); P.reset(1); // 0 and 1 are not prime
    for(int i=2;i<MAX;++i) {
        if (P.test(i)) {
            prime.push_back(i);
            for(int j=i<<1;j<MAX;j+=i) {
                P.reset(j);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    build();
    int N, L;
    while(std::cin >> N && N != 0) {
        L = N/2 + 1;
        bool found = false;
        for(int i=0;prime[i] <= L ;++i) {
            if (P.test(N-prime[i])) {
                std::cout << N << " = " << prime[i] << " + " << N-prime[i] << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Goldbach's conjecture is wrong." << std::endl;
        }
    }
    return 0;
}
