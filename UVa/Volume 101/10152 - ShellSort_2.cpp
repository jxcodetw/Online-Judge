#include <iostream>
#include <queue>
#include <stack>
#include <map>

std::string org[210], des[210];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, N;
    std::cin >> T;
    while(T--) {
        std::cin >> N;
        std::cin.ignore();
        for(int i=0;i<N;++i) { std::getline(std::cin, org[i]); }
        for(int i=0;i<N;++i) { std::getline(std::cin, des[i]); }
        
        int j = N-1;
        for(int i=N-1;i>=0;--i) {
            if (org[i] == des[j]) {
                j -= 1;
            }
        }
        
        while(j >= 0) {
            std::cout << des[j--] << std::endl;
        }
        
        std::cout << std::endl;
    }
    return 0;
}
