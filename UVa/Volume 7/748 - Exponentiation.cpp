#include <cstdio>
#include <cstring>

const int MAX = 500+10;
char n1[MAX], n2[MAX];
int ans[MAX];


void mul() {
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
    while(ans[x] == 0) {
        x -= 1;
    }
    for(int i=0;i<=x;++i) {
        n1[i] = ans[x-i] + '0';
    }
    n1[x+1] = '\0';
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while(scanf("%s", n1) == 1) {
        scanf("%d", &n);
        int dotPos = -1;
        for(int i=0;i<strlen(n1);++i) {
            if (dotPos == -1) {
                if (n1[i] == '.') {
                    dotPos = i;
                }
            } else {
                n1[i-1] = n1[i];
            }
        }
        
        n1[5] = '\0';
        strcpy(n2, n1);
        for(int i=1;i<n;++i) {
            mul();
        }
        
        dotPos = (int)strlen(n1) - (5-dotPos) * n;
        if (dotPos < 0) {
            putchar('.');
            while(dotPos++ < 0) {
                putchar('0');
            }
            dotPos = -1;
        }
        int x = (int)strlen(n1) - 1;
        while(n1[x] == '0') {
            x -= 1;
        }
        for(int i=0;i<=x;++i) {
            if (i == dotPos) {
                putchar('.');
            }
            putchar(n1[i]);
        }
        putchar('\n');
    }
    return 0;
}
