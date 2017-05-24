#include <iostream>
#include <set>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, n, b;
    while(std::cin >> N && N!=0) {
        std::multiset<int> S;
        long long int sum = 0;
        for(int i=0;i<N;++i) {
            std::cin >> n;
            for(int j=0;j<n;++j) {
                std::cin >> b;
                S.insert(b);
            }
            auto low = S.begin();
            auto high = --S.end();
            sum += *high - *low;
            S.erase(low);
            S.erase(high);
        }
        std::cout << sum << std::endl;
    }
    
    return 0;
}
