#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

const int MAX = 100+10;
char buf[MAX][MAX];

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 0, max = INT_MIN;
    memset(buf, 0, sizeof(buf));
    for(t = 0;fgets(buf[t], MAX, stdin); ++t) {
        max = std::max(max, (int)strlen(buf[t]));
    }
    max -= 1; // trim \n
    for(int j=0;j<max;++j) {
        for(int i=t-1;i>=0;--i) {
            char c = buf[i][j];
            if (c == '\0' || c == '\n') {
                c = ' ';
            }
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}
