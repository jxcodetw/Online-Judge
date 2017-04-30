#include <cstdio>
#include <cstdlib>

char c;
int T;
bool found;

void nextChar() {
    while((c=getchar()) && (c == ' ' || c == '\n'));
}

int parseNum() {
    int num = 0;
    bool neg = false;
    if (c == '-') {
        neg = true;
        nextChar();
    }
    while(c >= '0' && c <= '9') {
        num = num * 10 + c - '0';
        nextChar();
    }
    return neg ? -num : num;
}

bool parseTree(int sum) {
    nextChar();
    bool nullnode = (c == ')');
    if (!nullnode) {
        sum += parseNum();
        bool lnull = parseTree(sum);
        bool rnull = parseTree(sum);
        if (lnull && rnull && T == sum) {
            found = true;
        }
    }
    nextChar();
    return nullnode;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    while(scanf("%d", &T) == 1) {
        nextChar();
        found = false;
        parseTree(0);
        ungetc(c, stdin);
        if (found) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
