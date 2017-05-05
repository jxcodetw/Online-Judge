#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::string line;
    bool flag = false;
    while(std::getline(std::cin, line)) {
        for(int i=0;i<line.length();++i) {
            if (line[i] == '\"') {
                if (flag) {
                    putchar('\'');putchar('\'');
                } else {
                    putchar('`');putchar('`');
                }
                flag = !flag;
            } else {
                putchar(line[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}

