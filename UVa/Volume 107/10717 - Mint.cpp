#include <iostream>

typedef long long int lli;

lli gcd(lli a, lli b) {
    while(b!=0) {
        lli r = a%b;
        a = b;
        b = r;
    }
    return a;
}

lli lcm(lli a, lli b) {
    return (a/gcd(a, b)) * b;
}

lli C[100];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, T;
    while(std::cin >> N >> T && (N!=0&&T!=0)) {
        for(int i=0;i<N;++i) {
            std::cin >> C[i];
        }
        while(T--) {
            lli t, a = -1, b = 1e15;
            std::cin >> t;
            for(int i=0;i<N;++i) {
                for(int j=i+1;j<N;++j) {
                    for(int k=j+1;k<N;++k) {
                        for(int l=k+1;l<N;++l) {
                            lli _lcm = lcm(C[i], lcm(C[j], lcm(C[k], C[l])));
                            lli mod = t % _lcm;
                            if (mod == 0) {
                                a = b = t;
                                i = j = k = l = N;
                            } else {
                                lli _a = (t >= _lcm ? t-mod : 0);
                                lli _b = _a + _lcm;
                                if (_a > a) {a = _a;}
                                if (_b < b) {b = _b;}
                            }
                        }
                    }
                }
            }
            std::cout << a << ' ' << b << std::endl;
        }
    }
    return 0;
}
