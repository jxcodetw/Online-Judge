#include <cstdio>
#include <climits>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    const int MAX = 100+10;
    
    int N;
    int arr[MAX][MAX] = {0};
    while(~scanf("%d", &N)) {
        for(int i=1;i<=N;++i) {
            for(int j=1;j<=N;++j) {
                scanf("%d", &arr[i][j]);
                arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }
        
        int max = INT_MIN;
        for(int r1=1;r1<=N;++r1) {
            for(int c1=1;c1<=N;++c1) {
                for(int r2=r1;r2<=N;r2++) {
                    for(int c2=c1;c2<=N;c2++) {
                        max = std::max(max,
                              arr[r2][c2] - arr[r2][c1-1] - arr[r1-1][c2] + arr[r1-1][c1-1]);
                    }
                }
            }
        }
        
        printf("%d\n", max);
    }
    
    return 0;
}
