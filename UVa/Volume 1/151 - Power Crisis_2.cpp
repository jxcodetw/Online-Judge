#include <cstdio>

const int MAX = 100+10;
const int TARGET = 13;

bool check(int n, int m) {
    int next[MAX], head = 1, prev = n;
    for(int i=1;i<=n;++i) {
        next[i] = i+1;
    }
    next[n] = 1;
    
    bool result = false;
    for(int i=1;i<=n;++i) {
        if (head == TARGET) {
            result = (i == n);
            break;
        }
        next[prev] = next[head];
        head = next[head];
        
        for(int j=1;j<m;++j) {
            prev = head;
            head = next[head];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    int ans[MAX], N;
    for(int i=13;i<100;++i) {
        int m = 1;
        while(check(i, m) == false) {
            m += 1;
        }
        ans[i] = m;
    }
    while(scanf("%d", &N) == 1 && N != 0) {
        printf("%d\n", ans[N]);
    }
    return 0;
}
