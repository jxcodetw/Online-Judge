#include <iostream>
#include <sstream>
#include <stack>

bool check(std::string &line) {
    std::stringstream ss(line);
    std::stack<int> S;
    S.push(0);
    int n;
    while(ss >> n) {
        if (n < 0) {
            S.push(n);
            S.push(0);
        } else {
            if (S.size() == 1 || S.top() >= n) {
                return false;
            }
            S.pop();
            
            if (S.top() != -n) {
                return false;
            }
            S.pop();
            
            S.top() += n;
        }
        
    }
    
    return S.size() == 1;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string line;
    while(std::getline(std::cin, line)) {
        if (check(line)) {
            puts(":-) Matrioshka!");
        } else {
            puts(":-( Try again.");
        }
    }
    return 0;
}
