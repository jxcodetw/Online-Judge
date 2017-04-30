#include <iostream>
#include <sstream>
#include <stack>

enum BlockType {
    SHELL,
    TOY,
};

class Block {
public:
    int val;
    enum BlockType type;
    Block() {}
    Block(int val, enum BlockType type) : val(val), type(type) {}
};

bool check(std::string &line) {
    std::stringstream ss(line);
    std::stack<Block> S;
    int n;
    while(ss >> n) {
        if (n < 0) {
            Block b(-n, SHELL);
            S.push(b);
        } else {
            Block b;
            int sum = 0;
            while(true) {
                if (S.empty()) {
                    return false;
                }
                b = S.top();
                if (b.type == SHELL) {
                    break;
                } else {
                    sum += b.val;
                    S.pop();
                }
            }
            if (b.val != n || sum >= n) {
                return false;
            }
            
            S.pop();
            b.type = TOY;
            S.push(b);
        }
    }
    while(!S.empty()) {
        Block b = S.top();
        if (b.type == SHELL) {
            return false;
        } else {
            S.pop();
        }
    }
    return true;
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
