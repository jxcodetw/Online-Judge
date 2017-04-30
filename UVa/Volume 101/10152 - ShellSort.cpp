#include <iostream>
#include <queue>
#include <stack>
#include <map>

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
        std::string name;
        
        std::map<std::string, int> Mt;
        std::stack<std::string> So, St;
        for(int i=0;i<N;++i) {
            std::getline(std::cin, name);
            So.push(name);
        }
        for(int i=0;i<N;++i) {
            std::getline(std::cin, name);
            Mt.insert(std::make_pair(name, i));
            St.push(name);
        }
        
        std::priority_queue<std::pair<int, std::string>> PQ;
        while(!So.empty()) {
            std::string to = So.top();
            std::string tt = St.top();
            if (to == tt) {
                So.pop();
                St.pop();
            } else {
                PQ.push(std::make_pair(Mt[to], to));
                So.pop();
            }
        }
        
        for(std::pair<int, std::string> t;!PQ.empty();PQ.pop()) {
            t = PQ.top();
            std::cout << t.second << std::endl;
        }
        
        std::cout << std::endl;
    }
    return 0;
}
