//
// Created by Xin Sun on 2020-12-25.
//
#include <iostream>
using namespace std;
int data[1000005];

int f(int x){
    if(x == 1 || x == 0) return 1;
    return f(x-1) + f(x-2);
}

int main()
{
    data[1] = 1;
    data[2] = 2;

    for (int i = 3; 1; i++){
        data[i] = data[i-1] + data[i-2];
        if(data[i] >= 4000000){
            break;
        }
    }
    int ans = 0;
    for (int i = 1; 1; i++){
        if(data[i] % 2 == 0) {
            ans += data[i];
        }
        if(data[i] >= 4000000){
            break;
        }
    }
    int ans2 = 0;
    int a = 1, b = 2;
    int tmp;
    while(b <= 4000000){
        if(b % 2 == 0){
            ans2 += b;
        }
        tmp = b;
        b = a + b;
        a = tmp;
    }
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}
