//
// Created by Xin Sun on 2020-12-26.
//
// 记忆化
// 递归 + 记忆化
/*
 * int num[50] = {0};
 * int func(int i){
 *  if(n == 1) return 1;
 *  if(n == 2) return 2;
 *  if(num[n]) return num[n];
 *  return num[n] = func(n-1) + func(n-2);
 * }
 */

#include <iostream>
using namespace std;
long long data[100];
long long f(long long i){
    if(i == 1) return 1;
    if(i == 2) return 2;
    if(data[i]){
        return data[i];
    }

    return data[i] = f(i-1) + f(i-2);
}

long long num[10000005];
long long func(long long n){
    if(n == 1) return 1;
    if(n <= 10000000 && num[n]){
        return num[n];
    }

    long long t;
    if(n % 2 == 0){
        t = func(n / 2) + 1;
    }else{
        t = func(3 * n + 1) + 1;
    }
    if(n <= 10000000){
        num[n] = t;
    }
    return t;
}
int main()
{
    //int n;
    //cin >> n;
    //cout << f(n) << endl;
    int ans = 1;
    for(int i = 2; i <= 1000000; i++){
        if(func(ans) < func(i)){
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}