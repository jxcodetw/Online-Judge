#include <iostream>

void left(std::string &c) {
    char t = c[1];
    c[1] = c[2];
    c[2] = c[4];
    c[4] = c[3];
    c[3] = t;
}

void down(std::string &c) {
    char t = c[0];
    c[0] = c[4];
    c[4] = c[5];
    c[5] = c[1];
    c[1] = t;
}

void clockwise(std::string &c) {
    char t = c[0];
    c[0] = c[2];
    c[2] = c[5];
    c[5] = c[3];
    c[3] = t;
}

bool rotate(std::string c1, std::string c2) {
    for(int j=0;j<4;++j) {
        left(c1);
        if (c1 == c2) {
            return true;
        }
    }
    down(c1);down(c1);
    for(int j=0;j<4;++j) {
        left(c1);
        if (c1 == c2) {
            return true;
        }
    }
    down(c1);
    for(int j=0;j<4;++j) {
        clockwise(c1);
        if (c1 == c2) {
            return true;
        }
    }
    down(c1);down(c1);
    for(int j=0;j<4;++j) {
        clockwise(c1);
        if (c1 == c2) {
            return true;
        }
    }
    left(c1);
    for(int j=0;j<4;++j) {
        down(c1);
        if (c1 == c2) {
            return true;
        }
    }
    left(c1);left(c1);
    for(int j=0;j<4;++j) {
        down(c1);
        if (c1 == c2) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string line;
    while(std::cin >> line) {
        if (rotate(line.substr(0, 6), line.substr(6, 12))) {
            std::cout << "TRUE" << std::endl;
        } else {
            std::cout << "FALSE" << std::endl;
        }
    }
    return 0;
}
