#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    std::string str;
    while(std::getline(std::cin, str)) {
        std::transform(str.begin(), str.end(), str.begin(),
                       [](char c) { return c - 7; });
        std::cout << str << std::endl;
    }
    return 0;
}
