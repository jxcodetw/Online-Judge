#include <cstdio>

const int MAX = 1300000;
int T[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    T[0] = T[1] = 1;
    for(int i=2;i<MAX;++i) {
        if (T[i] == 0) {
            for(int j=i+i;j<MAX;j+=i) {
                T[j] = 1;
            }
        }
    }
    
    int n, lp, rp;
    while(scanf("%d", &n) == 1 && n != 0) {
        lp = rp = n;
        while(T[lp] == 1) {
            lp -= 1;
        }
        while(T[rp] == 1) {
            rp += 1;
        }
        printf("%d\n", rp - lp);
    }
    return 0;
}

