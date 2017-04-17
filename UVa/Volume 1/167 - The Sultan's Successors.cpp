#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>

int queenPos[92][8];

bool isSafe(int (&q)[8]) {
    for(int i=1;i<8;++i) {
        for(int j=0;j<i;++j) {
            if (i-j == abs(q[i]-q[j])) {
                return false;
            }
        }
    }
    return true;
}

void buildTable() {
    int q[8];
    for(int i=0;i<8;++i) {
        q[i] = i;
    }
    
    int cnt = 0;
    while(std::next_permutation(q, q+8)) {
        if (isSafe(q)) {
            for(int i=0;i<8;++i) {
                queenPos[cnt][i] = q[i] + i * 8;
            }
            cnt++;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    int N;
    int board[64];
    
    buildTable();
    while(scanf("%d", &N) == 1) {
        while(N--) {
            for(int i=0;i<64;++i) {
                scanf("%d", &board[i]);
            }
            
            int max = INT_MIN;
            for(int i=0;i<92;++i) {
                int sum = 0;
                for(int j=0;j<8;++j) {
                    sum += board[queenPos[i][j]];
                }
                max = std::max(max, sum);
            }
            
            printf("%5d\n", max);
        }
    }
    return 0;
}
