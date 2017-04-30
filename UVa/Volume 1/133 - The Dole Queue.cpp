#include <cstdio>
#include <cstring>

bool dole[30];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, k, m;
    while(scanf("%d%d%d", &N, &k, &m) == 3 && (N!=0&&k!=0&&m!=0)) {
        memset(dole, false, sizeof(dole));
        int picked = 0, clkwise = N, rclkwise = -1;
        while(picked < N) {
            for(int i=0;i<k;++i) {
                do {
                    rclkwise = (rclkwise + 1) % N;
                } while(dole[rclkwise]);
            }
//            printf("rclk = %d\n", rclkwise);
            for(int i=0;i<m;++i) {
                do {
                    clkwise = (clkwise - 1 + N) % N;
                } while(dole[clkwise]);
            }
//            printf("clk = %d\n", clkwise);
            
            
            if (picked > 0) {
                putchar(',');
            }
            
            if (clkwise == rclkwise) {
                dole[clkwise] = true;
                printf("%3d", clkwise+1);
                picked += 1;
            } else {
                dole[clkwise] = true;
                dole[rclkwise] = true;
                
                printf("%3d%3d", rclkwise+1, clkwise+1);
                
                picked += 2;
            }
//            break;
        }
        putchar('\n');
    }
    return 0;
}
