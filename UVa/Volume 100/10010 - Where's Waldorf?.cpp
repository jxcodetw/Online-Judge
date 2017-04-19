#include <cstdio>
#include <cstring>

const int MAX = 50 + 10;
int M, N;
char buf[MAX][MAX];
char str[MAX];

void strToLower(char s[]) {
    int size = (int)strlen(s);
    for(int i=0;i<size;++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

bool check(int i, int j) {
    int len = (int)strlen(str);
    int x = 0;
    x=0;while(j+x< N&&str[x]==buf[i][j+x]){++x;}if(x==len){return true;}
    x=0;while(j-x>=0&&str[x]==buf[i][j-x]){++x;}if(x==len){return true;}
    x=0;while(i+x< M&&str[x]==buf[i+x][j]){++x;}if(x==len){return true;}
    x=0;while(i-x>=0&&str[x]==buf[i-x][j]){++x;}if(x==len){return true;}
    
    x=0;while(i+x< M&&j+x< N&&str[x]==buf[i+x][j+x]){++x;}if(x==len){return true;}
    x=0;while(i-x>=0&&j-x>=0&&str[x]==buf[i-x][j-x]){++x;}if(x==len){return true;}
    x=0;while(i-x>=0&&j+x< N&&str[x]==buf[i-x][j+x]){++x;}if(x==len){return true;}
    x=0;while(i+x< M&&j-x>=0&&str[x]==buf[i+x][j-x]){++x;}if(x==len){return true;}
    return false;
}

void locate() {
    for(int i=0;i<M;++i) {
        for(int j=0;j<N;++j) {
            if (check(i, j)) {
                printf("%d %d\n", i+1, j+1);
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, k;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d", &M, &N);
        for(int i=0;i<M;++i) {
            scanf("%s", buf[i]);
            strToLower(buf[i]);
        }
        scanf("%d", &k);
        for(int i=0;i<k;++i) {
            scanf("%s", str);
            strToLower(str);
            locate();
        }
        if (t != 0) {putchar('\n');}
    }
    return 0;
}
