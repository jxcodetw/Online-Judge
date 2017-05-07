#include <iostream>
#include <sstream>
int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    std::string line;
    double speed = 0, dist = 0;
    int last = 0;
    std::cout.precision(2);
    while(std::getline(std::cin, line)) {
        int cur = ((line[0]-'0')*10 + line[1]-'0')*3600 +
                  ((line[3]-'0')*10 + line[4]-'0')*60 +
                  ((line[6]-'0')*10 + line[7]-'0');
        dist += ((double)(cur-last)/3600)*speed;
        last = cur;
        if (line.length() == 8) {
            // query
            std::cout << line << ' ' << std::fixed << dist << " km" << std::endl;
        } else {
            std::stringstream ss(line.substr(8));
            ss >> speed;
        }
    }
    return 0;
}
