//
// Created by Xin Sun on 2020-12-28.
//

#include <iostream>

using namespace std;
int m, n, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005], msec[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> num[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            utd[i][j] = max(utd[i-1][j], utd[i-1][j-1]) + num[i][j];
        }
    }

    for(int i = n; i > 0; i--){
        for(int j = 1; j <= i; j++){
            dtu[i][j] = max(dtu[i+1][j], dtu[i+1][j+1]) + num[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }

    for(int i = 2; i <= n; i++){
        int max = 0, second = 0, maxIndex = 0;
        for (int j = 1; j <= i; j++){
            if(ans[i][j] > max){
                second = max;
                max = ans[i][j];
                maxIndex = j;
            }else if(ans[i][j] > second){
                second = ans[i][j];
            }
        }
        mmax[i] = maxIndex;
        msec[i] = second;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(x == 1){
            cout << -1 << endl;
        }else if(mmax[x] == y){
            cout << msec[x] << endl;
        }else{
            cout << dtu[1][1] << endl;
        }
    }
    return 0;
}
