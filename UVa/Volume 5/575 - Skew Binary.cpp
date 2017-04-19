#include <cstdio>
#include <cstring>

const int MAX = 10000+10;
char line[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%s", line) == 1 && strcmp(line, "0")) {
        int pow = 2, sum = 0;
        for(int i=(int)strlen(line)-1;i>=0;--i) {
            sum += (line[i] - '0') * (pow-1);
            pow *= 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
