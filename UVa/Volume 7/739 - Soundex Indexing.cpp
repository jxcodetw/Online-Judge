#include <iostream>
#include <cstdio>
#include <cstring>

char buf[50], ans[50];
int M[] = {-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5, 5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int last, code, idx;
    puts("         NAME                     SOUNDEX CODE");
    while(scanf("%s", buf) == 1) {
        printf("         ");
        last = M[buf[0]-'A'];
        ans[0] = buf[0];
        idx = 1;
        for(int i=1;i<strlen(buf);++i) {
            code = M[buf[i]-'A'];
            if (code != last) {
                if (code != -1) {
                    ans[idx++] = code + '0';
                }
            }
            last = code;
        }
        while(idx < 4) {
            ans[idx++] = '0';
        }
        ans[4] = '\0';
        printf("%-25s%s\n", buf, ans);
    }
    puts("                   END OF OUTPUT");
    return 0;
}

