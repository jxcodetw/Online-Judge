#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int base, A, B;
    while(scanf("%d%d%d", &base, &A, &B) == 3) {
        int carry = 0, len = 0, x = A;
        do {
            int tmp = x * B + carry;
            carry = tmp / base;
            x = tmp % base;
            len += 1;
        } while(carry != 0 || x != A);
        
        printf("%d\n", len);
    }
    return 0;
}
