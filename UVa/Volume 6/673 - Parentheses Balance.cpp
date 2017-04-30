#include <cstdio>
#include <cstring>

char buf[200], stack[200];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, top;
    scanf("%d\n", &N);
    while(N--) {
        fgets(buf, sizeof(buf), stdin);
        top = 0;
        bool valid = true;
        for(int i=0;i<strlen(buf) && valid;++i) {
            char c = buf[i];
            switch(c) {
                case '(':
                case '[':
                    stack[++top] = c;
                    break;
                case ')':
                    if (top > 0 && stack[top] == '(') {
                        top -= 1;
                    } else {
                        valid = false;
                    }
                    break;
                case ']':
                    if (top > 0 && stack[top] == '[') {
                        top -= 1;
                    } else {
                        valid = false;
                    }
                    break;
            }
        }
        
        if (valid && top == 0) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
