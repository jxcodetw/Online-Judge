#include <cstdio>
#include <cstring>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    const int TARGET = 13 - 1;
    
    bool region[100+10];
    int N;
    while(scanf("%d", &N) == 1 && N != 0) {
        for(int m=1;m<N;++m) {
            for(int i=0;i<N;++i) {
                region[i] = false;
            }
            
            int idx = (1-m+N) % N;
            int i;
            for(i=1; i<=N;++i) {
                for(int skip = 1; skip < m || region[idx] == true; idx = (idx+1) % N) {
                    if (region[idx] == false) {
                        skip += 1;
                    }
                }
                region[idx] = true;
                if (idx == TARGET) {
                    break;
                }
            }
            if (i == N) {
                printf("%d\n", m);
                break;
            }
        }
    }
    
    return 0;
}
