#include <cstdio>

int sol[10], row[10], T[100][10];
int idx = 0;

int abs(int n) {
    return n < 0 ? -n : n;
}

bool check(int col) {
    int x = sol[col];
    int y = col;
    for(int c=col-1;c>0;--c) {
        int r = sol[c];
        if (abs(r-x) == abs(c-y)) {
            return false;
        }
    }
    return true;
}

void build(int col) {
    if (col == 9) {
        for(int i=1;i<=8;++i) {
            T[idx][i] = sol[i];
        }
        idx += 1;
        return;
    }
    for(int i=1;i<=8;++i) {
        if (!row[i]) {
            row[i] = 1;
            sol[col] = i;
            if (check(col)) {
                build(col+1);
            }
            row[i] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
//    std::ios_base::sync_with_stdio(false);
    
    build(1);
    
    int N, r, c;
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &r, &c);
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8");
        putchar('\n');
        
        int cnt = 1;
        for(int i=0;i<idx;++i) {
            if (T[i][c] == r) {
                printf("%2d      %d %d %d %d %d %d %d %d\n", cnt++,
                T[i][1], T[i][2], T[i][3], T[i][4],
                T[i][5], T[i][6], T[i][7], T[i][8]);
            }
        }
        if (N) {putchar('\n');}
    }
    return 0;
}
