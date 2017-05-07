#include <iostream>
#include <map>

int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
std::string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::map<std::string, std::string> M;
    for(int i=1;i<4000;++i) {
        int n = i;
        std::string rom, num = std::to_string(n);
        for(int j=12;j>=0;--j) {
            while(n >= value[j]) {
                n -= value[j];
                rom += symbol[j];
            }
        }
        M[num] = rom;
        M[rom] = num;
    }
    
    std::string str;
    while(std::cin >> str) {
        std::cout << M[str] << std::endl;
    }
    
    return 0;
}
