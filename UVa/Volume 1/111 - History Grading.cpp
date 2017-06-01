#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

int M[100], S[100], LCS[100][100];

int solve(int N) {
    memset(LCS, 0, sizeof(LCS));
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=N;++j) {
            if (M[i] == S[j]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = std::max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    return LCS[N][N];
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N = 1, n;
    bool start = false;
    std::string str;
    while(std::getline(std::cin, str)) {
        std::vector<int> V;
        std::stringstream ss(str);
        while(ss >> n) {
            V.push_back(n);
        }
        if (V.size() == 1) {
            N = V[0];
            start = false;
        } else {
            if (!start) {
                start = true;
                for(int i=0;i<V.size();++i) {
                    M[V[i]] = i+1;
                }
            } else {
                for(int i=0;i<V.size();++i) {
                    S[V[i]] = i+1;
                }
                std::cout << solve(N) << std::endl;
            }
        }
    }
    return 0;
}
