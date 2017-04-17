#include <cstdio>
#include <cstring>

const char M[] = " .xW";
int dish[40+10];
int cnt[40+10];

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    int N;
    int dna[10];
    while(scanf("%d", &N) == 1) {
        bool first = true;
        while(N--) {
            if (first) {
                first = false;
            } else {
                putchar('\n');
            }
            
            for(int i=0;i<10;++i) {
                scanf("%d", &dna[i]);
            }
            memset(dish, 0, sizeof(dish));
            dish[20] = 1;
            for(int d=0;d<50;++d) {
                for(int i=1;i<=40;++i) {
                    putchar(M[dish[i]]);
                    cnt[i] = dish[i-1] + dish[i] + dish[i+1];
                }
                putchar('\n');
                for(int i=1;i<=40;++i) {
                    dish[i] = dna[cnt[i]];
                }
            }
        }
    }
    return 0;
}
