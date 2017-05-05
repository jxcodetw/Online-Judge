#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::string word = "";
    char c;
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            while (word.length() > 0) {
                putchar(word.back());
                word.pop_back();
            }
            putchar(c);
        } else {
            word += c;
        }
    }
    return 0;
}

