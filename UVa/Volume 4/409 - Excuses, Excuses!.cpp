#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int notAlpha(int c) {
    return !std::isalpha(c);
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int K, E, t = 0;
    std::string str;
    while(std::cin >> K >> E) {
        std::vector<std::string> keyword, excuse;
        std::vector<int> matchCnt;
        for(int i=0;i<K;++i) {
            std::cin >> str;
            keyword.push_back(str);
        }
        std::cin.ignore();
        int max = INT_MIN;
        for(int i=0;i<E;++i) {
            std::getline(std::cin, str);
            excuse.push_back(str);
            std::transform(str.begin(), str.end(), str.begin(), tolower);
            for(int i=0;i<str.length();++i) {
                if (notAlpha(str[i])) {
                    str[i] = ' ';
                }
            }
            int cnt = 0;

            std::stringstream ss(str);
            std::string word;
            while(ss >> word) {
                for(int i=0;i<K;++i) {
                    if (word == keyword[i]) {
                        cnt+=1;
                        break;
                    }
                }
            }
            matchCnt.push_back(cnt);
            max = std::max(max, cnt);
        }
        
        std::cout << "Excuse Set #" << ++t << std::endl;
        for(int i=0;i<E;++i) {
            if (matchCnt[i] == max) {
                std::cout << excuse[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
