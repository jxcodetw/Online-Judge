/* from http://knightzone.org/?p=3166 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  while( scanf("%d", &N) != EOF ){
    vector<string> filename(N);

    int maxLength = 0;
    for( int i = 0 ; i < N ; ++i ){
      cin >> filename[i];
      maxLength = max((int)filename[i].length(), maxLength);
    }

    sort(filename.begin(), filename.end());

    int column = 60 / (maxLength + 2);
    if( column == 0 ){
      column = 1;
    }
    int maxRow = N / column + ((N % column != 0)? 1 : 0);

    for( int i = 0 ; i < 60 ; ++i ){
      printf("-");
    }
    printf("\n");

    for( int i = 0 ; i < maxRow ; ++i ){
      for( int j = 0 ; j < column ; ++j ){
        if( i + j * maxRow >= N ){
          break;
        }
        printf("%-*s", maxLength+2, filename[i + j * maxRow].c_str());
      }
      printf("\n");
    }


  }
  return 0;
}
