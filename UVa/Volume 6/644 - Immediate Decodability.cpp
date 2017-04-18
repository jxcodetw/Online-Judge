#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool check(std::vector<std::string> &V) {
    size_t pos;
    std::sort(V.begin(), V.end());
    for(int i=0;i<V.size()-1;++i) {
        for(int j=i+1;j<V.size();++j) {
            pos = V[j].find(V[i]);
            if (pos != std::string::npos && pos == 0) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string str;
    std::vector<std::string> V;
    int t = 0;
    while(std::cin >> str) {
        if (str == "9") {
            t += 1;
            if (check(V)) {
                std::cout << "Set " << t << " is immediately decodable" << std::endl;
            } else {
                std::cout << "Set " << t << " is not immediately decodable" << std::endl;
            }
            V.clear();
        } else {
            V.push_back(str);
        }
    }
    return 0;
}
