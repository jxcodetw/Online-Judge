#include <cstdio>
#include <cstring>

char P[256], C[256], M[256], buf[100];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T;
    scanf("%d\n\n", &T);
    while(T--) {
        for(int i=0;i<256;++i) {
            M[i] = i;
        }
        fgets(P, sizeof(P), stdin);
        fgets(C, sizeof(C), stdin);
        printf("%s%s", C, P);
        for(int i=0;i<strlen(P);++i) {
            M[P[i]] = C[i];
        }
        while(fgets(buf, sizeof(buf), stdin) && strcmp(buf, "\n")) {
            for(int i=0;i<strlen(buf);++i) {
                putchar(M[buf[i]]);
            }
        }
        if (T) {putchar('\n');}
    }
    return 0;
}

