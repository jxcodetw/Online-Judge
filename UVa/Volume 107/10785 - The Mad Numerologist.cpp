#include <cstdio>
#include <cstring>

const char vowel[]       = "AUEOI";
const char cons[]        = "JSBKTCLDMVNWFXGPYHQZR";
const char vowelSorted[] = "AEIOU";
const char consSorted[]  = "BCDFGHJKLMNPQRSTVWXYZ";
int cnt[256];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N, n;
    scanf("%d", &N);

    for(int t=1;t<=N;++t) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        printf("Case %d: ", t);
        int i, consCnt = n/2, vowelCnt = (n+1)/2;
        for(i=0;vowelCnt > 21;++i) {
            cnt[vowel[i]] = 21;
            vowelCnt -= 21;
        }
        cnt[vowel[i]] = vowelCnt;
        
        for(i=0;consCnt > 5; ++i) {
            cnt[cons[i]] = 5;
            consCnt -= 5;
        }
        cnt[cons[i]] = consCnt;
        
        
        int vi = 0, ci = 0;
        for(i=1;i<=n;++i) {
            if ((i & 1) == 1) {
                while(cnt[vowelSorted[vi]] == 0) {
                    vi += 1;
                }
                cnt[vowelSorted[vi]] -= 1;
                putchar(vowelSorted[vi]);
            } else {
                while(cnt[consSorted[ci]] == 0) {
                    ci += 1;
                }
                cnt[consSorted[ci]] -= 1;
                putchar(consSorted[ci]);
            }
        }
        putchar('\n');
    }
    return 0;
}
