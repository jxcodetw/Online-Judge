#include <iostream>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, n, d, D;
    std::cin >> T;
    for(int t=1;t<=T;++t) {
        std::cout << "Case " << t << ": ";
        std::cin >> n;
        std::string subj;
        std::map<std::string, int> M;
        for(int i=0;i<n;++i) {
            std::cin >> subj >> d;
            M[subj] = d;
        }
        std::cin >> D;
        std::cin >> subj;
        auto iter = M.find(subj);
        if (iter == M.end()) {
            puts("Do your own homework!");
        } else {
            if (iter->second <= D) {
                puts("Yesss");
            } else if (iter->second <= D + 5) {
                puts("Late");
            } else {
                puts("Do your own homework!");
            }
        }
    }
    return 0;
}

