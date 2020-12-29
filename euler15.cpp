//
// Created by Xin Sun on 2020-12-28.
// DP

#include <iostream>
using namespace std;

long long dp[25][25];

int main(){
    for(int i=1; i<=21; i++){
        for(int j=1; j<=21; j++){
            if(i == 1 && j == 1 ){
                dp[i][j] = 1;
            }else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[21][21] << endl;

    return 0;
}

