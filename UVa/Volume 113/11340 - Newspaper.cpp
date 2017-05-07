#include <iostream>
#include <iomanip>
#include <cstring>

int val[256];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int T, K, v;
    unsigned char c;
    std::cin >> T;
    while(T--) {
        std::cin >> K;
        memset(val, 0, sizeof(val));
        
        for(int i=0;i<K;++i) {
            std::cin >> c >> v;
            val[c] = v;
        }
        std::cin >> K;
        std::cin.ignore();
        int sum = 0;
        for(int i=0;i<K;++i) {
            while((char)(c=getchar()) != EOF && c != '\n') {
                sum += val[c];
            }
        }
        
        printf("%.2lf$\n", sum / 100.0);
    }
    return 0;
}

