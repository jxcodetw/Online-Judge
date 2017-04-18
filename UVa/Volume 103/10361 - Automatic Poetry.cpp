#include <iostream>
#include <algorithm>

int filter(int c) {
    return c == '<' || c == '>';
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::string l1, l2, s2, s3, s4, s5;
    while(std::cin >> N) {
        std::cin.ignore();
        while(N--) {
            std::getline(std::cin, l1);
            std::getline(std::cin, l2);
            int i = 0, j = 0;
            i = (int)l1.find('<', i);
            j = (int)l1.find('>', i);
            s2 = l1.substr(i + 1, j-i-1);
            i = (int)l1.find('<', i + 1);
            s3 = l1.substr(j+1, i-j-1);
            j = (int)l1.find('>', i + 1);
            s4 = l1.substr(i + 1, j-i - 1);
            s5 = l1.substr(j + 1);
            l1.erase(std::remove_if(l1.begin(), l1.end(), filter), l1.end());
            std::cout << l1 << std::endl;
            std::cout << l2.substr(0, l2.find("...")) << s4 << s3 << s2 << s5 << std::endl;
        }
    }
    return 0;
}
