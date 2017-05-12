#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, P, n;
    std::cin >> N;
    while(N--) {
        std::cin >> P;
        std::cin.ignore();
        int min = std::numeric_limits<int>::max();
        std::vector<int> ans;
        for(int i=1;i<=P;++i) {
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            int cnt = 0;
            while(ss >> n) {
                cnt += 1;
            }
            if (min > cnt) {
                min = cnt;
                ans.clear();
                ans.push_back(i);
            } else if (min == cnt) {
                ans.push_back(i);
            }
        }
        
        std::cout << ans[0];
        for(int i=1;i<ans.size();++i) {
            std::cout << ' ' << ans[i];
        }
        std::cout<<std::endl;
    }
    return 0;
}
