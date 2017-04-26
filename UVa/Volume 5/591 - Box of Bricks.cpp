#include <iostream>
#include <algorithm>

int block[50+10];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, sum, avg, t = 1;
    while(std::cin >> N && N != 0) {
        sum = 0;
        for(int i=0;i<N;++i) {
            std::cin >> block[i];
            sum += block[i];
        }
        avg = sum / N;
        
        sum = 0;
        for(int i=0;i<N;++i) {
            sum += std::max(0, block[i]-avg);
        }
        
        std::cout << "Set #" << t++ << std::endl;
        std::cout << "The minimum number of moves is " << sum << "." << std::endl << std::endl;
    }
    return 0;
}
