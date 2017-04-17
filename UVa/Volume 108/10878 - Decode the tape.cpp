#include <cstdio>
#include <cstring>

char buf[256];
char M[] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1};

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    fgets(buf, sizeof(buf), stdin);
    while(fgets(buf, sizeof(buf), stdin) && strcmp(buf, "___________\n")) {
        char c = 0;
        for(int i=2;i<=9;++i) {
            if (buf[i] == 'o') {
                c += M[i];
            }
        }
        putchar(c);
    }
    return 0;
}
