#include <cstdio>
#include <cmath>

char buf[256];

inline double min(double a, double b) {
    return a < b ? a : b;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    double H, M;
    while(fgets(buf, sizeof(buf), stdin)) {
        if (buf[1] == ':') {
            H = buf[0] - '0';
            M = (buf[2] - '0') * 10 + buf[3] - '0';
        } else {
            H = (buf[0] - '0') * 10 + buf[1] - '0';
            M = (buf[3] - '0') * 10 + buf[4] - '0';
        }
        if (H == 0 && M == 0) {break;}
        H = H*30 + 30*(M/60);
        M *= 6;
        
        double minDiff = min(fabs(H-M), fabs(M-H));
        printf("%.3lf\n", min(minDiff, 360-minDiff));
    }
    return 0;
}
