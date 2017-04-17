#include <cstdio>
#include <cstring>
#include <cctype>

const int MAX = 132 + 10;

char buf[MAX];

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    while(fgets(buf, sizeof(buf), stdin)) {
        int cnt = 0;
        for(int i=0;i<strlen(buf);++i) {
            if (isdigit(buf[i])) {
                cnt += buf[i] - '0';
            } else if (isalpha(buf[i]) || buf[i] == '*') {
                for(char c = (buf[i] == 'b') ? ' ' : buf[i]; cnt != 0; --cnt) {
                    putchar(c);
                }
            } else {
                putchar('\n');
            }
        }
    }
    
    return 0;
}
