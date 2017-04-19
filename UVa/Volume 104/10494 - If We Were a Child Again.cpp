#include <cstdio>
#include <cstring>

const int MAX = 10000+10;
char line[MAX], den[MAX], quo[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    long long int der, tmp, rem, acc;
    int derLen;
    char op;
    while(fgets(line, sizeof(line), stdin)) {
        memset(quo, 0, sizeof(quo));
        sscanf(line, "%s %c %lld", den, &op, &der);
        derLen = 0; tmp = der;
        while(tmp > 0) {
            tmp /= 10;
            derLen += 1;
        }
        if (strlen(den) < derLen) {
            derLen = (int)strlen(den);
        }
        
        rem = 0;
        for(int i=0; i<derLen-1;++i) {
            rem = rem * 10 + den[i] - '0';
        }
        
        int j = 0, t = 0;
        for(int i=derLen-1;i<strlen(den);++i) {
            rem = rem * 10 + den[i] - '0';
            t = 0; acc = 0;
            while(rem >= acc+der) {
                t += 1;
                acc += der;
            }
            quo[j++] = t + '0';
            rem -= acc;
        }
        quo[j] = '\0';
        
        if (op == '/') {
            if (strcmp(quo, "0") == 0) {
                puts("0");
            } else {
                char *ptr = quo;
                while(*ptr == '0') {ptr++;}
                puts(ptr);
            }
        } else {
            printf("%lld\n", rem);
        }
    }
    
    return 0;
}
