#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

int M[100], S[100];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N = 1, n;
    bool start = false;
    std::string str;
    while(std::getline(std::cin, str)) {
        std::vector<int> V;
        std::stringstream ss(str);
        while(ss >> n) {
            V.push_back(n);
        }
        if (V.size() == 1) {
            N = V[0];
            start = false;
        } else {
            if (!start) {
                start = true;
                for(int i=0;i<V.size();++i) {
                    M[i+1] = V[i];
                }
            } else {
                for(int i=0;i<V.size();++i) {
                    S[V[i]] = M[i+1];
                }
                { // LIS
                    std::vector<int> tmp;
                    tmp.push_back(S[1]);
                    for(int i=2;i<=N;++i) {
                        int k = S[i];
                        if (k > tmp.back()) {
                            tmp.push_back(k);
                        } else {
                            *std::lower_bound(tmp.begin(), tmp.end(), k) = k;
                        }
                    }
                    std::cout << tmp.size() << std::endl;
                }
            }
        }
    }
    return 0;
}
