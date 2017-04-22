#include <cstdio>

const int MAX = 50 + 10;
int arr[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    while(N--) {
        int L, swapCnt = 0;
        scanf("%d", &L);
        for(int i=0;i<L;++i) {
            scanf("%d", &arr[i]);
        }
        
        for(int i=0;i<L-1;++i) {
            for(int j=1;j<L-i;++j) {
                if (arr[j] < arr[j-1]) {
                    int t = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = t;
                    swapCnt += 1;
                }            }
        }
        
        printf("Optimal train swapping takes %d swaps.\n", swapCnt);
    }
    return 0;
}
