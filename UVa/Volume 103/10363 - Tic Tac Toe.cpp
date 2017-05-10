#include <iostream>

bool check() {
    int x = 0, o = 0;
    std::string B[3];
    std::cin >> B[0] >> B[1] >> B[2];
    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            if (B[i][j] == 'X') {
                x+=1;
            } else if (B[i][j] == 'O') {
                o+=1;
            }
        }
    }
    if (!(x-o == 1 || x-o==0)) {
        return false;
    }
    
    bool xw = false, ow = false;
    for(int i=0;i<3;++i) {
        if (B[i][0] == B[i][1] && B[i][1] == B[i][2]) {
            if (B[i][0] == 'O') {
                ow = true;
            } else if (B[i][0] == 'X') {
                xw = true;
            }
        }
    }
    for(int i=0;i<3;++i) {
        if (B[0][i] == B[1][i] && B[1][i] == B[2][i]) {
            if (B[0][i] == 'O') {
                ow = true;
            } else  if (B[0][i] == 'X') {
                xw = true;
            }
        }
    }
    if (B[0][0] == B[1][1] && B[1][1] == B[2][2]) {
        if (B[1][1] == 'O') {
            ow = true;
        } else  if (B[1][1] == 'X') {
            xw = true;
        }
    }
    if (B[0][2] == B[1][1] && B[1][1] == B[2][0]) {
        if (B[1][1] == 'O') {
            ow = true;
        } else  if (B[1][1] == 'X') {
            xw = true;
        }
    }
    
    if (x - o == 1 && ow) {
        return false;
    }
    
    if (x - o == 0 && xw) {
        return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T;
    std::cin >> T;
    while(T--) {
        if (check()) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}
