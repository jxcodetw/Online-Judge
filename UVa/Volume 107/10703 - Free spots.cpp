#include <iostream>
#include <cstring>
#include <algorithm>

bool board[1000][1000];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int W, H, N;
    while (std::cin >> W >> H >> N && (W!=0)) {
        memset(board, false, sizeof(board));
        int freeSpots = W * H;
        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            
            if (x1 > x2) {std::swap(x1, x2);}
            if (y1 > y2) {std::swap(y1, y2);}
            for(int x=x1;x<=x2;++x) {
                for(int y=y1;y<=y2;++y) {
                    if (board[x][y] == false) {
                        board[x][y] = true;
                        freeSpots -= 1;
                    }
                }
            }
        }
        if (freeSpots == 0) {
            std::cout << "There is no empty spots." << std::endl;
        } else if (freeSpots == 1) {
            std::cout << "There is one empty spot." << std::endl;
        } else {
            std::cout << "There are " << freeSpots << " empty spots." << std::endl;
        }
    }
    return 0;
}
