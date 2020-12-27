//
// Created by Xin Sun on 2020-12-25.
//
#include <iostream>
using namespace std;
int func(int x){
    int row = x;
    int rev = 0;
    while(x > 0){
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == row;
}
int main()
{
    int ans = 0;
    int a, b;
    for (int i = 100; i < 1000; i++){
        for (int j = i; j < 1000; j++){
            int t = i * j;
            if(func(t) && ans < t){
                ans = t;
                a = i;
                b = j;
            }
        }
    }

    cout << a << "*" << b << endl;
    cout << ans << endl;
    return 0;
}