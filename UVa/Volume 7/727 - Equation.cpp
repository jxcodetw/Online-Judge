#include <iostream>
#include <stack>

char level[256];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    level['('] = -1;
    level[')'] = 0;
    level['+'] = level['-'] = 1;
    level['*'] = level['/'] = 2;
    
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::cin.get();
    while(N--) {
        char c;
        std::stack<char> S;
        while(std::cin.get(c) && c != '\n') {
            std::cin.get();
            if (c >= '0' && c <= '9') {
                std::cout << c;
                continue;
            }
            if (c == '(') {
                S.push(c);
            } else if (c == ')') {
                while(S.top() != '(') {
                    std::cout << S.top();S.pop();
                }
                S.pop();
            } else {
                while (!S.empty() && level[S.top()] >= level[c]) {
                    std::cout << S.top();S.pop();
                }
                S.push(c);
            }
        }
        while(!S.empty()) {
            std::cout << S.top();
            S.pop();
        }
        std::cout << std::endl;
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
