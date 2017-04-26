// ref http://programming-study-notes.blogspot.tw/2014/02/uva-107-cat-in-hat.html
//
#include <cstdio>
#include <cmath>
#include <climits>

const double EPS = 1e-10;

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int H, W, N = 0;
    while(scanf("%d%d", &H, &W) == 2 && (H!=0 && W!=0)) {
        double tmp = log(H) / log(W);
        for(int l=1, r=INT_MAX-10; l != r;) {
            N = (l + r) / 2;
            double test = log(N+1) / log(N);
            if (test - tmp > EPS) {
                l = N + 1;
            } else if (test - tmp < -EPS) {
                r = N;
            } else {
                break;
            }
        }
        
        long long notWorkNum = 0;
        long long notWorkHeight = 0;
        int c = 1;
        for(int i=0;H>1;++i) {
            notWorkNum += c;
            notWorkHeight += c * H;
            c *= N;
            H /= (N+1);
        }
        printf("%lld %lld\n", notWorkNum, notWorkHeight+c);
    }
    return 0;
}
