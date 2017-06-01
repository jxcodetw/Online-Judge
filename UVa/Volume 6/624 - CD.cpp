#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

int dp[30][10010], t[30];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int M, N, track;
    while(std::cin >> M >> N) {
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=N;++i) {
            std::cin >> track;
            t[i] = track;
            for(int j=0;j<track;++j) {
                dp[i][j] = dp[i-1][j];
            }
            for(int j=track;j<=M;++j) {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-track] + track);
            }
        }
        
        std::stack<int> S;
        for(int X = N, C = M;X > 0;--X) {
            if (dp[X][C] != dp[X-1][C]) {
                S.push(t[X]);
                C -= t[X];
            }
        }
        while(!S.empty()) {
            std::cout << S.top() << " ";
            S.pop();
        }
        std::cout << "sum:" << dp[N][M] << std::endl;
    }
    return 0;
}
