#include <iostream>
#include <sstream>
#include <algorithm>

const int MAX = 30 + 10;
int stack[MAX], heap[MAX];
int len, num;

void flip(int e) {
    printf("%d ", len - e);
    int b = 0;
    while(b<e) {
        std::swap(stack[b++], stack[e--]);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::string line;
    while(std::getline(std::cin, line)) {
        puts(line.c_str());
        std::stringstream ss(line);
        for(len=0;ss>>num;++len) {
            heap[len] = stack[len] = num;
        }
        std::make_heap(heap, heap+len);
        for(int i=0;i<len;++i) {
            int j, slen = len - i, max;
            std::pop_heap(heap, heap+slen);
            max = heap[slen-1];
            for(j=0;j<slen;++j) {
                if (stack[j] == max) {
                    break;
                }
            }
            if (j != slen-1) {
                if (j != 0) {
                    flip(j);
                }
                flip(slen-1);
            }
        }
        putchar('0');
        putchar('\n');
    }
    return 0;
}
