#include <cstdio>
#include <cstring>

int cal[4000];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, N, P, h;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &P);
        memset(cal, 0, sizeof(cal));
        for(int i=0;i<P;++i) {
            scanf("%d", &h);
            for(int i=1;i<=N;i+=2) {
                for(int j=0;i<=N && j < 5;++i, ++j) {
                    if (i % h == 0) {
                        cal[i] = 1;
                    }
                }
            }
        }
        
        int sum = 0;
        for(int i=1;i<=N;++i) {
            sum += cal[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
