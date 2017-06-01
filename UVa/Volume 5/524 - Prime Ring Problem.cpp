#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>

std::vector<int> P[20];
std::bitset<50> T;

int N;
int ans[20];
bool used[20];

void backtrack(int pos) {
    if (pos == N && T.test(ans[pos]+1)) {
        std::cout << 1;
        for(int i=2;i<=N;++i) {
            std::cout << " " << ans[i];
        }
        std::cout << std::endl;
    }
    for(auto num : P[ans[pos]]) {
        if (!used[num] && num <= N) {
            used[num] = true;
            ans[pos+1] = num;
            backtrack(pos+1);
            used[num] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    T.flip();
    for(int i=2;i<50;++i) {
        if (T.test(i)) {
            for(int j=i+i;j<50;j+=i) {
                T.reset(j);
            }
        }
    }
    
    for(int i=1;i<=16;++i) {
        for(int j=1;j<=16;++j) {
            if (i != j && T.test(i+j)) {
                P[i].push_back(j);
            }
        }
    }
    
    int c = 1;
    bool first = true;
    while(std::cin >> N) {
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
        std::cout << "Case " << c++ << ":" << std::endl;
        
        memset(used, 0, sizeof(used));
        ans[1] = 1;
        used[1] = true;
        backtrack(1);
        
    }
    return 0;
}
