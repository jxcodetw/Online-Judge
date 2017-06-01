#include <iostream>
#include <algorithm>

std::string ans;
int N, H, A;
void solve(int p, int d) {
    if (d == A) {
        std::cout << ans << std::endl;
        return;
    }
    int e = std::min(p+H+1, N);
    for(int i=p;i<e;++i) {
        ans[i] = '0';
        solve(i+1, d+1);
        ans[i] = '1';
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while(T--) {
        std::cin >> N >> H;
        A = N-H;
        ans = "";
        for(int i=0;i<N;++i) {
            ans += '1';
        }
        solve(0, 0);
        if (T) {std::cout << std::endl;}
    }
    return 0;
}
