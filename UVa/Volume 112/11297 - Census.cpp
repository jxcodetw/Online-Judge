/*
 refs
 concepts:
 [1] http://pisces.ck.tp.edu.tw/~peng/index.php?action=showfile&file=f220f2d6b33ae091978ebf59d2af5908bc8190b51
 implementation:
 [2] https://chrt.github.io/2017/03/04/uva11297-census/
 */
#include <iostream>
#include <climits>
#include <algorithm>

const int MAX = 500 + 10;
int N;

struct Data {
    int mx, mn;
};

struct Node {
    Data data;
    
    void pull(Node *l, Node *r) {
        data.mx = std::max(l->data.mx, r->data.mx);
        data.mn = std::min(l->data.mn, r->data.mn);
    }
} segment_tree[MAX*4][MAX*4];

int C[MAX][MAX];

Node* build_y(Node *t, int idx, int X, int L, int R, Node *lt=0, Node *rt=0) {
    Node *now = &t[idx];
    if (L == R) {
        if (lt == 0) {
            now->data.mx = now->data.mn = C[X][L];
        } else {
            now->pull(&lt[idx], &rt[idx]);
        }
        return now;
    }
    int m = (L+R)/2;
    Node *l = build_y(t, (idx<<1)+1, X, L, m, lt, rt);
    Node *r = build_y(t, (idx<<1)+2, X, m+1, R, lt, rt);
    now->pull(l, r);
    return now;
}

Node* build_x(int idx, int L, int R) {
    Node *now = &segment_tree[idx][0];
    if (L == R) {
        build_y(now, 0, L, 0, N-1);
        return now;
    }
    int m = (L+R)/2;
    Node *l = build_x((idx<<1)+1, L, m);
    Node *r = build_x((idx<<1)+2, m+1, R);
    build_y(now, 0, -1, 0, N-1, l, r);
    now->pull(l, r);
    return now;
}

int xL, xR, yL, yR;
Data query_y(int idx, int X, int L, int R) {
    Data res;
    if (L > yR || R < yL) {
        return {-INT_MAX, INT_MAX};
    }
    if (yL <= L && R <= yR) {
        return segment_tree[X][idx].data;
    }
    int m = (L+R)/2;
    Data l = query_y((idx<<1)+1, X, L, m);
    Data r = query_y((idx<<1)+2, X, m+1, R);
    res.mx = std::max(l.mx, r.mx);
    res.mn = std::min(l.mn, r.mn);
    return res;
}

Data query_x(int idx, int L, int R) {
    Data res;
    if (L > xR || R < xL) {
        return {-INT_MAX, INT_MAX};
    }
    if (xL <= L && R <= xR) {
        return query_y(0, idx, 0, N-1);
    }
    int m = (L+R)/2;
    Data l = query_x((idx<<1)+1, L, m);
    Data r = query_x((idx<<1)+2, m+1, R);
    res.mx = std::max(l.mx, r.mx);
    res.mn = std::min(l.mn, r.mn);
    return res;
}

int uX, uY;

Node* update_y(Node *t, int idx, int L, int R, int v, Node *lt=0, Node *rt=0) {
    Node *now = &t[idx];
    if (L > uY || R < uY) {
        return now;
    }
    if (L == uY && R == uY) {
        if (lt == 0) {
            now->data.mx = now->data.mn = v;
        } else {
            now->pull(&lt[idx], &rt[idx]);
        }
        return now;
    }
    int m = (L+R)/2;
    Node *l = update_y(t, (idx<<1)+1, L, m, v, lt, rt);
    Node *r = update_y(t, (idx<<1)+2, m+1, R, v, lt, rt);
    now->pull(l, r);
    return now;
}

Node* update_x(int idx, int L, int R, int v) {
    Node *now = &segment_tree[idx][0];
    if (L > uX || R < uX) {
        return now;
    }
    if (L == uX && R == uX) {
        update_y(now, 0, 0, N-1, v);
        return now;
    }
    int m = (L+R)/2;
    Node *l = update_x((idx<<1)+1, L, m, v);
    Node *r = update_x((idx<<1)+2, m+1, R, v);
    update_y(now, 0, 0, N-1, v, l, r);
    now->pull(l, r);
    return now;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int Q, x1, y1, x2, y2, v;
    char op;
    std::cin >> N;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            std::cin >> C[i][j];
        }
    }
    
    build_x(0, 0, N-1);
    
    std::cin >> Q;
    while(Q--) {
        std::cin >> op;
        if (op == 'q') {
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) {std::swap(x1, x2);}
            if (y1 > y2) {std::swap(y1, y2);}
            xL = x1-1;xR = x2-1;
            yL = y1-1;yR = y2-1;
            Data res = query_x(0, 0, N-1);
            std::cout << res.mx << " " << res.mn << std::endl;
        } else {
            std::cin >> x1 >> y1 >> v;
            uX = x1-1;
            uY = y1-1;
            update_x(0, 0, N-1, v);
        }
    }
    return 0;
}
