#include <iostream>
#include <cstring>
#include <algorithm>

const int SHIFT = 100000;
const int MAX = 100000+SHIFT+100;
int segment_tree[1000000];
int A[MAX], cnt[MAX], start[MAX];

void build(int l, int r, int idx) {
    if (l == r) {
        segment_tree[idx] = cnt[A[l]];
    } else if (l < r) {
        int m = (l+r)/2, lidx = (idx<<1)+1, ridx = lidx+1;
        build(l,   m, lidx);
        build(m+1, r, ridx);
        segment_tree[idx] = std::max(segment_tree[lidx], segment_tree[ridx]);
    }
}

int query(int l, int r, int a, int b, int idx) {
    if (a > r || b < l) {
        return -1;
    } else if (a <= l && r <= b) {
        return segment_tree[idx];
    } else {
        int m = (l+r)/2, lidx = (idx<<1)+1, ridx = lidx+1;
        return std::max(query(l, m, a, b, lidx), query(m+1, r, a, b , ridx));
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, Q, a, b;
    while(std::cin >> N && N != 0) {
        std::cin >> Q;
        memset(cnt, 0, sizeof(cnt));
        memset(start, -1, sizeof(start));
        for(int i=0;i<N;++i) {
            std::cin >> A[i];
            A[i] += SHIFT;
            cnt[A[i]] += 1;
            if (cnt[A[i]] == 1) {
                start[A[i]] = i;
            }
        }
        
        /* build segment tree */
        build(0, N-1, 0);
        
        for(int i=0;i<Q;++i) {
            std::cin >> a >> b;
            a -= 1; b -= 1;
            if (A[a] == A[b]) {
                std::cout << b - a + 1 << std::endl;
            } else {
                /*
                   A[a] ... A[k-1] A[k] ... A[j] A[j+1] ... A[b]
                   A[a] == A[k-1] && A[k-1] != A[k]
                   A[b] == A[j+1] && A[j+1] != A[j]
                */
                int k = (start[A[a]] + cnt[A[a]]);
                int cnt1 = k - a;
                int j = start[A[b]] - 1;
                int cnt2 = b - j;
                int ans = std::max(cnt1, cnt2);
                if (k <= j) {
                    ans = std::max(ans, query(0, N-1, k, j, 0));
                }
                std::cout << ans << std::endl;
            }
        }
    }
    return 0;
}
