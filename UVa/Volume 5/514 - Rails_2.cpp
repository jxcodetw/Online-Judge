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
            std::queue<int> Qin;
            std::vector<int> Qout;
            std::stack<int> S;
            Qout.push_back(n);
            Qin.push(1);
            for(int i=2;i<=N;++i) {
                std::cin >> n;
                Qout.push_back(n);
                Qin.push(i);
            }
            
            bool ans = true;
            for(auto v : Qout) {
                while((S.empty() || S.top() != v) && !Qin.empty()) {
                    S.push(Qin.front());Qin.pop();
                }
                if (S.top() == v) {
                    S.pop();
                } else {
                    ans = false;
                    break;
                }
            }
            
            if (ans) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
