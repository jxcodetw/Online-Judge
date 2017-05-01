#include <cstdio>
#include <cstring>

int pile[10000];
int left, right;

void tree(int pos) {
    int n;
    scanf("%d", &n);
    if (n > -1) {
        if (pos < left)  { left  = pos; }
        if (pos > right) { right = pos; }
        pile[pos] += n;
        tree(pos-1);
        tree(pos+1);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, mid = 10000/2, t = 0;
    while(scanf("%d", &n) == 1 && n != -1) {
        printf("Case %d:\n", ++t);
        memset(pile, 0, sizeof(pile));
        left = right = mid;
        pile[mid] = n;
        tree(mid-1);
        tree(mid+1);
        for(int i=left;i<right;++i) {
            printf("%d ", pile[i]);
        }
        printf("%d", pile[right]);
        putchar('\n');putchar('\n');
    }
    return 0;
}

