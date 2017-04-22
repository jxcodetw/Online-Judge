#include <cstdio>
#include <cstring>

const int MAX = 10000+10;
int vis[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int Z, I, M, L, t = 1;
    while(scanf("%d%d%d%d", &Z, &I, &M, &L) == 4 && (Z!=0&&I!=0&&M!=0&&L!=0)) {
        memset(vis, 0xFF, sizeof(vis));
        for(int i=0;;++i) {
            if (vis[L] != -1) {
                printf("Case %d: %d\n", t++, i-vis[L]);
                break;
            } else {
                vis[L] = i;
                L = (Z*L+I) % M;
            }
        }
    }
    return 0;
}
