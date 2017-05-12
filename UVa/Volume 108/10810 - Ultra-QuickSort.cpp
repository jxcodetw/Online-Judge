#include <cstdio>
#include <cstring>

int a[500000], t[500000];
long long ans;

void mergeSort(int l, int r) {
    if (l+1 == r) {return;}
    int m = (l+r) / 2;
    int t1 = l, t2 = m, t3 = t1;
    mergeSort(l, m);
    mergeSort(m, r);
    while(t1 < m && t2 < r) {
        if (a[t1] < a[t2]) {
            t[t3++] = a[t1++];
        } else {
            t[t3++] = a[t2++];
            ans += m-t1;
        }
    }
    while(t1<m) {t[t3++] = a[t1++];}
    while(t2<m) {t[t3++] = a[t2++];}
    memcpy(&a[l], &t[l], (r-l)*sizeof(int));
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N;
    while(scanf("%d", &N) == 1 && N != 0) {
        ans = 0;
        for(int i=0;i<N;++i) {
            scanf("%d", &a[i]);
            t[i] = a[i];
        }
        mergeSort(0, N);
        printf("%lld\n", ans);
    }
    return 0;
}
