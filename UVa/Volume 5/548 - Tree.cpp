#include <climits>
#include <iostream>
#include <sstream>

const int MAX = 10000+10;
int M[MAX], ibuf[MAX], pbuf[MAX];
int min, leaf;

void build(int pb, int pe, int ib, int ie, int sum) {
    if (pb > pe || ib > ie) { return; }
    int v = pbuf[pe];
    int idx = M[v];
    sum += v;
    if (pb == pe) {
        if (sum < min) {
            min = sum;
            leaf = v;
        } else if (sum == min) {
            if (v < leaf) {
                leaf = v;
            }
        }
    }
    build(pb, pb+idx-ib-1, ib, idx-1, sum);
    build(pb+idx-ib, pe-1, idx+1, ie, sum);
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string line;
    int N, n;
    while(std::getline(std::cin, line)) {
        std::stringstream iss(line);
        N = 0;
        while(iss >> n) {
            M[n] = N;
            ibuf[N++] = n;
        }
        std::getline(std::cin, line);
        std::stringstream pss(line);
        N = 0;
        while(pss >> n) {
            pbuf[N++] = n;
        }
       
        leaf = min = INT_MAX;
        build(0, N-1, 0, N-1, 0);
        
        std::cout << leaf << std::endl;
    }
    
    return 0;
}
