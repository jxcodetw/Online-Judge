#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

struct Seg {
    double x1, x2, r;
};

double calc(std::vector<Seg> &S, double x) {
    double r = 1;
    for(auto s : S) {
        if (x >= s.x1 && x <= s.x2) {
            r *= s.r;
        }
    }
    return r;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cout.precision(3);
    
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        double x1, y1, x2, y2, r;
        std::vector<double> X;
        std::vector<Seg> S;
        std::cin >> n;
        while(n--) {
            std::cin >> x1 >> y1 >> x2 >> y2 >> r;
            if (x1 > x2) {
                double t = x1;
                x1 = x2;
                x2 = t;
            }
            X.push_back(x1);
            X.push_back(x2);
            S.push_back({x1, x2, r});
        }
        std::unique(X.begin(), X.end());
        std::sort(X.begin(), X.end());
        
        std::cout << X.size() + 1 << std::endl;
        std::cout << std::fixed << "-inf " << X[0] << ' ' << calc(S, X[0]-1) << std::endl;
        for(int i=0;i<X.size()-1;++i) {
            std::cout << std::fixed << X[i] << ' ' << X[i+1] << ' '
                      << calc(S, (X[i]+X[i+1])/2) <<  std::endl;
        }
        std::cout << std::fixed << X[X.size()-1] << " +inf " << calc(S, X[0]-1) << std::endl;
        
        if (T) {std::cout << std::endl;}
    }
    return 0;
}

