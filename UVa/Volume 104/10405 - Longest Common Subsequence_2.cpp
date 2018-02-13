#include <iostream>
#include <algorithm>
#include <cstring>

int dp[1010];

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
            for(int j=(int)s2.length()-1;j>=0;--j) {
                if (s1[i] == s2[j]) {
                    dp[j+1] = dp[j] + 1;
                }
            }
            for(int j=0;j<s2.length();++j) {
                if (s1[i] != s2[j]) {
                    dp[j+1] = std::max(dp[j+1], dp[j]);
                }
            }
        }
        
        std::cout << dp[s2.length()] << std::endl;;
    }
    return 0;
}
