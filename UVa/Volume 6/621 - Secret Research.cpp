#include <iostream>

char decrypt(std::string &s) {
    if (s == "1" || s == "4" || s == "78") {
        return '+';
    }
    if (s.substr(s.length()-2, s.length()) == "35") {
        return '-';
    }
    if (s.front() == '9' && s.back() == '4') {
        return '*';
    }
    return '?';
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string seq;
    int N;
    std::cin >> N;
    while(N--) {
        std::cin >> seq;
        std::cout << decrypt(seq) << std::endl;
    }
    return 0;
}
