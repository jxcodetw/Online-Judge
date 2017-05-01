#include <cstdio>

bool flag;

int build() {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if (wl == 0) { wl = build(); }
    if (wr == 0) { wr = build(); }
    if (wl * dl != wr * dr) {
        flag = false;
    }
    return wl + wr;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        flag = true;
        build();
        puts(flag?"YES":"NO");
        if (T) {putchar('\n');}
    }
    return 0;
}

