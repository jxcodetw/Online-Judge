#include <iostream>
#include <map>
#include <algorithm>

const std::string T = "ABCDEFGHIJKLMNOPRSTUVWXY";
char M[256];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    for(char c='0';c<='9';++c) {
        M[c] = c;
    }
    for(int i=0;i<T.length();++i) {
        char c = T[i];
        M[c] = '2' + (i / 3);
    }
    
    int N, n;
    std::string phone;
    std::cin >> N;
    bool first = true;
    while(N--) {
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
        std::cin >> n;
        std::map<std::string, int> Map;
        for(int i=0;i<n;++i) {
            std::cin >> phone;
            
            std::string stdForm = "";
            for(int j=0;j<phone.length();++j) {
                if (phone[j] != '-') {
                    stdForm += M[phone[j]];
                    if (stdForm.length() == 3) {
                        stdForm += '-';
                    }
                }
            }
            
            auto iter = Map.find(stdForm);
            if (iter == Map.end()) {
                Map.insert(std::make_pair(stdForm, 1));
            } else {
                iter->second += 1;
            }
        }
        
        bool dup = false;
        for(auto iter : Map) {
            if (iter.second > 1) {
                dup = true;
                std::cout << iter.first << " " << iter.second << std::endl;
            }
        }
        if (!dup) {
            std::cout << "No duplicates." << std::endl;
        }
    }
    return 0;
}
