#include <cstdio>
#include <cstring>

const int MAX = 30;

int N;
int head[MAX];
int next[MAX];

bool same(int a, int b) {
    for(int n = a; n != -1; n = next[n]) {
        if (n == b) { return true; }
    }
    for(int n = b; n != -1; n = next[n]) {
        if (n == a) { return true; }
    }
    return false;
}

void reset(int n) {
    for(int i = n; next[i] != -1;) {
        head[next[i]] = next[i];
        int tmp = next[i];
        next[i] = -1;
        i = tmp;
    }
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    char arg1[MAX], arg2[MAX];
    int a, b;
    
    while(~scanf("%d", &N)) {
        for(int i=0;i<N;++i) {
            head[i] = i;
            next[i] = -1;
        }

        while(~scanf("%s", arg1) && strcmp(arg1, "quit")) {
            scanf("%d%s%d", &a, arg2, &b);
            
            if (same(a,b)) { continue; }
            
            if (strcmp(arg1, "move") == 0) { reset(a); }
            if (strcmp(arg2, "onto") == 0) { reset(b); }
            
            for(int i = 0; i < N; ++i) {
                if (head[i] == a) { head[i] = -1; break; }
                if (next[i] == a) { next[i] = -1; break; }
            }
            for(int i = b; i != -1; i = next[i]) {
                if (next[i] == -1) {
                    next[i] = a;
                    break;
                }
            }
        }
        // print result
        for(int i=0;i<N;++i) {
            printf("%d:", i);
            for(int j = head[i]; j != -1; j = next[j]) {
                printf(" %d", j);
            }
            putchar('\n');
        }
    }
    return 0;
}
