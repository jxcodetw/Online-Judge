#include <cstdio>
#include <climits>
#include <cstring>

char buf[256];
char record[100+10][5];
int cMap[256], wMap[256];
const char colors[] = "roygb";
const char wastes[] = "PGSAN";

int cityCnt = 0;
int cnt[5][5];

void reset() {
    cityCnt = 0;
    memset(cnt, 0, sizeof(cnt));
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    for(int i=0;i<strlen(colors);++i) { cMap[colors[i]] = i; }
    for(int i=0;i<strlen(wastes);++i) { wMap[wastes[i]] = i; }
    reset();
    
    while(scanf("%s", buf) == 1 && strcmp(buf, "#")) {
        if (buf[0] == 'e') {
            int min = INT_MAX, ans = -1;
            for(int i=1; i<=cityCnt; ++i) {
                int sum = 0;
                for(int j=0;j<5;++j) {
                    sum += cityCnt - cnt[j][record[i][j]];
                }
                if (sum < min) {
                    min = sum;
                    ans = i;
                }
            }
            printf("%d\n", ans);
            reset();
        } else {
            cityCnt += 1;
            for(int i=0;i<5;++i) {
                int c = cMap[buf[4*i]], w = wMap[buf[4*i+2]];
                record[cityCnt][c] = w;
                cnt[c][w] += 1;
            }
        }
    }
    return 0;
}
