#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n == 2) { return true; }
    if (n == 1 || n % 2 == 0) {return false;}
    int root = ceil(sqrt(n));
    for(int i=3;i<=root;i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int rev(int n) {
    int r = 0;
    while(n > 0) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, r;
    while(scanf("%d", &n) == 1) {
        if (isPrime(n)) {
            r = rev(n);
            if (r != n && isPrime(r)) {
                printf("%d is emirp.\n", n);
            } else {
                printf("%d is prime.\n", n);
            }
        } else {
            printf("%d is not prime.\n", n);
        }
    }
    return 0;
}

