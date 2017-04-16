#include <cstdio>
#include <cstring>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    const int MAX = 256;
    
    char str[MAX];
    while(scanf("%s", str) == 1 && strcmp(str, "#")) {
        if (std::next_permutation(str, str+strlen(str))) {
            puts(str);
        } else {
            puts("No Successor");
        }
    }
    return 0;
}
