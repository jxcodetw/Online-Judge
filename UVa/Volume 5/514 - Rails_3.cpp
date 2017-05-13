#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, n;
    while(std::cin >> N && N!=0) {
        while(std::cin >> n) {
            if (n == 0) {break;}
            std::queue<int> Qout;
            Qout.push(n);
            for(int i=1;i<N;++i) {
                std::cin >> n;
                Qout.push(n);
            }
            
            std::stack<int> S;
            for(int i=1;i<=N;++i) {
                S.push(i);
                while(!S.empty() && Qout.front() == S.top()) {
                    Qout.pop();
                    S.pop();
                }
            }
            
            if (S.empty()) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
