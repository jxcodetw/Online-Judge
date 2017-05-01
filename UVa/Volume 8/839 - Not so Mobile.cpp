#include <cstdio>

int build() {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if (wl == 0) {
        wl = build();
    }
    if (wr == 0) {
        wr = build();
    }
    if (wl >= 0 && wr >= 0 && wl * dl == wr * dr) {
        return wl + wr;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        if (build() != -1) {
            puts("YES");
        } else {
            puts("NO");
        }
        if (T) {putchar('\n');}
    }
    return 0;
}

