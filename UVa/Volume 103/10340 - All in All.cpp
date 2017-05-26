#include <iostream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string s1, s2;
    while(std::cin >> s1 >> s2) {
        int p1=0, p2=0;
        while(p1 < s1.length() && p2 < s2.length()) {
            if (s1[p1] == s2[p2]) {
                p1 += 1;
            }
            p2 += 1;
        }
        if (p1 == s1.length()) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
