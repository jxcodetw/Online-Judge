#include <iostream>
#include <algorithm>
#include <cstring>

int dp[1010][1010];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string s1, s2;
    while(std::getline(std::cin, s1)) {
        std::getline(std::cin, s2);
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<s1.length();++i) {
            for(int j=0;j<s2.length();++j) {
                if (s1[i] == s2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        std::cout << dp[s1.length()][s2.length()] << std::endl;;
    }
    return 0;
}
