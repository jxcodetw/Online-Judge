#include <cstdio>
#include <cstring>

int digit[10];

bool dup(int n) {
    for(int j=0;j<5;++j) {
        if (digit[n%10]++ == 1) {
            return true;
        }
        n/=10;
    }
    return false;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, u;
    bool first = true;
    while(scanf("%d", &N) == 1 && N != 0) {
        if (first) {
            first = false;
        } else {
            putchar('\n');
        }
        bool found = false;
        for(int i=01234;i<=98765;++i) {
            u = i * N;
            if (u >= 01234 && u <= 98765) {
                memset(digit, 0, sizeof(digit));
                if (dup(i) || dup(i*N)) {
                    continue;
                }
                found = true;
                printf("%05d / %05d = %d\n", i*N, i, N);
            }
        }
        if (found == false) {
            printf("There are no solutions for %d.\n", N);
        }
    }
    return 0;
}
