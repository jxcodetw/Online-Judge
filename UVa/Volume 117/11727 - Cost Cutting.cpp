#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, s[3];
    std::cin >> T;
    for(int t=1;t<=T;++t) {
        for(int i=0;i<3;++i) {
            std::cin >> s[i];
        }
        std::sort(s, s+3);
        std::cout << "Case " << t << ": " << s[1] << std::endl;
    }
    return 0;
}

