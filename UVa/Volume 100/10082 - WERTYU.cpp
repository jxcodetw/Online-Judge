#include <iostream>

char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
const int LEN = sizeof(keyboard) / sizeof(char);
char M[256];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    for(int i=0;i<256;++i) {
        M[i] = i;
    }
    for(int i=0;i<LEN-1;++i) {
        M[keyboard[i+1]] = keyboard[i];
    }
    std::string line;
    while(std::getline(std::cin, line)) {
        for(int i=0;i<line.length();++i) {
            line[i] = M[line[i]];
        }
        std::cout << line << std::endl;
    }
    
    return 0;
}

