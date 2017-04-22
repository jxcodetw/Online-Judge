#include <cstdio>
#include <cstring>

const int MAX = 1000+10;
int guess[MAX], secret[MAX];
bool vg[MAX], vs[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, t = 1;
    while(scanf("%d", &N) == 1 && N != 0) {
        printf("Game %d:\n", t++);
        for(int i=0;i<N;++i) {
            scanf("%d", &secret[i]);
        }
        for(;;) {
            int A = 0, B = 0;
            memset(vg, 0, sizeof(vg));
            memset(vs, 0, sizeof(vs));
            for(int i=0;i<N;++i) {
                scanf("%d", &guess[i]);
                if (secret[i] == guess[i]) {
                    vg[i] = vs[i] = true;
                    A += 1;
                }
            }
            if (guess[0] == 0) {
                break;
            }
            
            for(int i=0;i<N;++i) {
                for(int j=0;j<N && !vs[i];++j) {
                    if (vg[j]) {continue;}
                    if (secret[i] == guess[j]) {
                        vs[i] = vg[j] = true;
                        B += 1;
                    }
                }
            }
            
            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}
