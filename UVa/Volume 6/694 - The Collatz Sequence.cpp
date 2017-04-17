#include <cstdio>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long A, L, t = 0;
    while(scanf("%lld%lld", &A, &L) == 2 && A != -1 && L != -1) {
        long long cnt = 1;
        for(long long tmp = A;tmp != 1; ++cnt) {
            tmp = ((tmp & 1) == 0)
                ? tmp / 2
                : 3 * tmp + 1;
            if (tmp > L) { break; }
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", ++t, A, L, cnt);
    }
    return 0;
}
