#include <cstdio>
#include <cstring>

char buf[4096], img[40][40];
int idx;

void fill(int x, int y, int sz) {
    char c = buf[idx++];
    if (c == 'p') {
        sz /= 2;
        fill(x   ,y+sz,sz);
        fill(x   ,y   ,sz);
        fill(x+sz,y   ,sz);
        fill(x+sz,y+sz,sz);
    } else if (c == 'f') {
        for(int i=x;i<x+sz;++i) {
            for(int j=y;j<y+sz;++j) {
                img[i][j] = 1;
            }
        }
    }
}

void readTree() {
    idx = 0;
    fgets(buf, sizeof(buf), stdin);
    fill(0, 0, 32);
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N;
    scanf("%d\n", &N);
    while(N--) {
        memset(img, 0, sizeof(img));
        readTree();
        readTree();
        
        int sum = 0;
        for(int i=0;i<32;++i) {
            for(int j=0;j<32;++j) {
                sum += img[i][j];
            }
        }
        printf("There are %d black pixels.\n", sum);
    }
    return 0;
}

