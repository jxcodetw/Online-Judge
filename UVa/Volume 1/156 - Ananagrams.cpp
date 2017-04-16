#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    std::string str;
    std::map<std::string, std::string> M;
    std::map<std::string, int> cnt;
    while(std::cin >> str && str != "#") {
        std::string sorted = str;
        std::transform(sorted.begin(), sorted.end(), sorted.begin(), ::tolower);
        std::sort(sorted.begin(), sorted.end());
        M[sorted] = str;
        
        if (cnt.find(sorted) == cnt.end()) {
            cnt[sorted] = 1;
        } else {
            cnt[sorted] += 1;
        }
    }
    
    std::vector<std::string> ans;
    for(auto const &ent : cnt) {
        if (ent.second == 1) {
            ans.push_back(M[ent.first]);
        }
    }
    std::sort(ans.begin(), ans.end());
    for(auto const &s : ans) {
        std::cout << s << std::endl;
    }
    
    return 0;
}
