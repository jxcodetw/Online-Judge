#include <iostream>
#include <algorithm>

struct Node {
    int cl, cr, c;
    int left, right;
} segment_tree[300010];
int A[100010];

void merge(Node &node, Node &l, Node &r) {
    node.c  = std::max(l.c, r.c);
    node.cl = l.cl;
    node.cr = r.cr;
    if (l.right == r.left) {
        node.c = std::max(node.c, l.cr + r.cl);
        if (l.left  == r.left)  {node.cl += r.cl;}
        if (r.right == l.right) {node.cr += l.cr;}
    }
    node.left = l.left;
    node.right = r.right;
}

void build(int l, int r, int idx) {
    Node &node = segment_tree[idx];
    if (l == r) {
        node.c = node.cl = node.cr = 1;
        node.left = node.right = A[l];
    } else if (l < r) {
        int m = (l+r)/2, lidx = (idx<<1)+1, ridx = lidx+1;
        build(l,   m, lidx);
        build(m+1, r, ridx);
        merge(node, segment_tree[lidx], segment_tree[ridx]);
    }
}

Node query(int l, int r, int a, int b, int idx) {
    Node res;
    if (a > r || b < l) {
        res.c = -1;
    } else if (a <= l && r <= b) {
        return segment_tree[idx];
    } else {
        int m = (l+r)/2, lidx = (idx<<1)+1, ridx = lidx+1;
        Node nl = query(l,   m, a, b, lidx);
        Node nr = query(m+1, r, a, b, ridx);
        if (nl.c == -1) {
            res = nr;
        } else if (nr.c == -1) {
            res = nl;
        } else {
            merge(res, nl, nr);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, Q, a, b;
    while(std::cin >> N && N != 0) {
        std::cin >> Q;
        for(int i=0;i<N;++i) {
            std::cin >> A[i];
        }
        
        /* build segment tree */
        build(0, N-1, 0);
        
        for(int i=0;i<Q;++i) {
            std::cin >> a >> b;
            std::cout << query(0, N-1, a-1, b-1, 0).c << std::endl;
        }
    }
    return 0;
}
