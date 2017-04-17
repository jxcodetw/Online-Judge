#include <iostream>
#include <climits>
#include <algorithm>

const int WIDTH = 25;

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, record[13+10];
    while(std::cin >> N && N != 0) {
        std::cin.ignore();
        int min = INT_MAX;
        std::string str;
        for(int i=0;i<N;++i) {
            std::getline(std::cin, str);
            int cnt = 0;
            for(int j=0;j<WIDTH;++j) {
                if (str[j] != 'X') {
                    cnt++;
                }
            }
            record[i] = cnt;
            min = std::min(min, cnt);
        }
        
        int ans = 0;
        for(int i=0;i<N;++i) {
            ans += record[i] - min;
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}
