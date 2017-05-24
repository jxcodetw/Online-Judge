#include <iostream>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, n, b;
    while(std::cin >> N && N!=0) {
        std::map<int, int> M;
        long long int sum = 0;
        for(int i=0;i<N;++i) {
            std::cin >> n;
            for(int j=0;j<n;++j) {
                std::cin >> b;
                M[b] += 1;
            }
            auto low = M.begin();
            auto high = --M.end();
            sum += high->first - low->first;
            low->second -= 1;
            if (low->second == 0) {
                M.erase(low);
            }
            high->second -= 1;
            if (high->second == 0) {
                M.erase(high);
            }
        }
        std::cout << sum << std::endl;
    }
    
    return 0;
}
