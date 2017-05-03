#include <cstdio>

int abs(int n) {
    return n < 0 ? -n : n;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T;
    scanf("%d\n", &T);
    while(T--) {
        char a, b, c, d;
        scanf("%c%c%c%c", &a, &b, &c, &d);
        int first = (a-'A')*26*26+(b-'A')*26+(c-'A');
        int second;
        scanf("%d\n", &second);
        if (abs(first-second) <= 100) {
            puts("nice");
        } else {
            puts("not nice");
        }
    }
    return 0;
}

