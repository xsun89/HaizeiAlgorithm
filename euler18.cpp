//
// Created by Xin Sun on 2020-12-28.
//
#include <iostream>

using namespace std;

int n, num[20][20];
int main()
{
    int n = 15;
    for (int i = 1; i <=15; i++){
        for (int j = 1; j <= i; j++){
            cin >> num[i][j];
        }
    }
    int ans;
    for (int i = 2; i <= 15; i++){
        for (int j = 1; j <= i; j++){
            num[i][j] += max(num[i-1][j-1], num[i-1][j]);
            ans = max(ans, num[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
