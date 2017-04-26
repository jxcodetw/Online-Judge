#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    unsigned int N;
    while(scanf("%ud", &N) == 1 && N != 0) {
        unsigned int r = (unsigned int)floor(sqrt(N));
        if (r*r == N) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
