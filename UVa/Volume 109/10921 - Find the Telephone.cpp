#include <iostream>

char M[] = "22233344455566677778889999";

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string line;
    while(std::getline(std::cin, line)) {
        for(int i=0;i<line.length();++i) {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                line[i] = M[line[i] - 'A'];
            }
        }
        std::cout << line << std::endl;
    }
    
    return 0;
}

