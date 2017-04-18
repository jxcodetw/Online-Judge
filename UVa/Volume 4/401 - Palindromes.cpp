#include <cstdio>
#include <cstring>
                       //ABCDEFGHIJKLMNOPQRSTUVWXYZ
const char revAlpha[] = "Abbb3bbHILbJMbObbb2TUVWXY5";
                       //123456789
const char revNum[]   = "1SEbZbb8b";
char buf[256];
char M[256];

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int i, j, len;
    bool palindrome, mirrored;
    for(int t=0;t<strlen(revAlpha);++t) {
        M['A'+t] = revAlpha[t];
    }
    for(int t=0;t<strlen(revNum);++t) {
        M['1'+t] = revNum[t];
    }
    while(scanf("%s", buf) == 1) {
        len = (int)strlen(buf);
        palindrome = mirrored = true;
        for(i=0, j=len-1;i < j && (palindrome || mirrored) ;++i, --j) {
            if (buf[i] != buf[j]) {
                palindrome = false;
            }
            if (M[buf[i]] != buf[j]) {
                mirrored = false;
            }
        }
        
        // check center one
        mirrored &= (len & 1) ? M[buf[len/2]] == buf[len/2] : true;
        
        printf("%s", buf);
        if (palindrome) {
            if (mirrored) {
                puts(" -- is a mirrored palindrome.");
            } else {
                puts(" -- is a regular palindrome.");
            }
        } else {
            if (mirrored) {
                puts(" -- is a mirrored string.");
            } else {
                puts(" -- is not a palindrome.");
            }
        }
        putchar('\n');
    }
    return 0;
}
