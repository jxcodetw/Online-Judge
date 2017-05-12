#include <iostream>

union int32 {
    int val;
    unsigned char b[5];
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int32 n;
    while(std::cin >> n.val) {
        std::cout << n.val << " converts to ";
        n.b[4]=n.b[0];n.b[0]=n.b[3];n.b[3]=n.b[4];
        n.b[4]=n.b[1];n.b[1]=n.b[2];n.b[2]=n.b[4];
        std::cout << n.val << std::endl;
    }
    return 0;
}
