#include <cstdio>
#include <cstring>

const int MAX = 500+10;
char n1[MAX], n2[MAX];
int ans[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%s", n1) == 1) {
        scanf("%s", n2);
        memset(ans, 0, sizeof(ans));
        for(int i=(int)strlen(n2)-1, k=0;i>=0;--i, ++k) {
            for(int j=(int)strlen(n1)-1, l=k;j>=0;--j, ++l) {
                ans[l] += (n1[j]-'0') * (n2[i]-'0');
            }
        }
        for(int i=0;i<MAX-1; ++i) {
            ans[i+1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        int x = MAX-1;
        while(x >= 0 && ans[x] == 0) {
            x -= 1;
        }
        if (x == -1) {
            puts("0");
        } else {
            while(x >= 0) {
                printf("%d", ans[x--]);
            }
            putchar('\n');
        }
    }
    return 0;
}
