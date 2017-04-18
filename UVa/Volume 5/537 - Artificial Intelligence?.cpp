#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

double parse(std::string str) {
    double mul = 1, res;
    switch(str.back()) {
        case 'm': mul = 0.001;  str.pop_back(); break;
        case 'k': mul = 1000;   str.pop_back(); break;
        case 'M': mul = 1000000;str.pop_back(); break;
    }
    std::stringstream ss(str);
    ss >> res;
    return mul * res;
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(2);
    
    int N;
    std::string str, tmp;
    size_t fP, fU, fI;
    double P = -1, U = -1, I = -1;
    std::cin >> N;
    std::cin.ignore();
    for(int t=1;t<=N;++t) {
        std::getline(std::cin, str);
        fP = str.find("P=");
        fU = str.find("U=");
        fI = str.find("I=");
        
        if (fP != std::string::npos) {
            tmp = str.substr(fP+2);
            tmp = tmp.substr(0, tmp.find("W"));
            P = parse(tmp);
        }
        if (fU != std::string::npos) {
            tmp = str.substr(fU+2);
            tmp = tmp.substr(0, tmp.find("V"));
            U = parse(tmp);        }
        if (fI != std::string::npos) {
            tmp = str.substr(fI+2);
            tmp = tmp.substr(0, tmp.find("A"));
            I = parse(tmp);
        }
        std::cout << "Problem #" << t << std::endl;
        if (fP == std::string::npos) {
            std::cout << "P=" << U*I << "W" << std::endl;
        } else if (fU == std::string::npos) {
            std::cout << "U=" << P/I << "V" << std::endl;
        } else {
            std::cout << "I=" << P/U << "A" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
