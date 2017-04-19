#include <cstdio>
#include <cstring>

const int MAX = 100+10;
char buf[256];
int ans[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%s", buf) == 1 && strcmp(buf, "0")) {
        int len = (int)strlen(buf);
        for(int i=1;i<=len;++i) {
            ans[i] += buf[len-i] - '0';
            for(int j=i;ans[j]>=10;++j) {
                ans[j] -= 10;
                ans[j+1] += 1;
            }
        }
        len = 0;
    }
    int x = MAX-1;
    while(ans[x] == 0) {
        x -= 1;
    }
    while(x >=1 ) {
        printf("%d", ans[x--]);
    }
    putchar('\n');
    return 0;
}
