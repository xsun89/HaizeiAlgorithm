//
// Created by Xin Sun on 2020-12-26.
// direction array
// 11 12 13 14 15 16 17
// 21 22 23 24 25 26 27
// 31 32 33 34 35 36 37
// 41 42 43 44 45 46 47
//
//
// from 22 up {-1, 0} down {1, 0} left {0, -1} right {1, 0} right up {-1, 1} right down {1, 1}
// dirX={-1, 0, 1, 1}
// dirY={1, 1, 1, 0}    x' = x + dirX[k], y' = y + dirY[k] (k = 0, 1, 2, 3) ==>
//                      13, 23, 33, 32 four directions.

#include <iostream>
using namespace std;

int data[30][30];
int dirX[4] = {-1, 0, 1, 1};
int dirY[4] = {1, 1, 1, 0};

int main()
{
    for(int i = 5; i < 25; i++){
        for(int j = 5; j < 25; j++){
            cin >> data[i][j];
        }
    }
    int ans = 0;
    for(int i = 5; i <25; i++){
        for(int j = 5; j < 25; j++){
            for(int k = 0; k < 4; k++){
                int num = data[i][j];
                for(int l = 1; l < 4; l++){
                    int x = i + dirX[k] * l;
                    int y = j + dirY[k] * l;
                    int tmp = data[x][y];
                    num *= tmp;
                }
                ans = max(ans, num);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

