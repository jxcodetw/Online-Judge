#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::set<std::string> dict;
    std::string str, word;
    while(std::getline(std::cin, str)) {
        for(int i=0;i<str.length();++i) {
            if (!std::isalpha(str[i])) {
                str[i] = ' ';
            }
        }
        std::transform(str.begin(), str.end(), str.begin(), tolower);
        std::stringstream ss(str);
        while(ss >> word) {
            dict.insert(word);
        }
    }
    
    for(auto iter = dict.begin(); iter != dict.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    return 0;
}
