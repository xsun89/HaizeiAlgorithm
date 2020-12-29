//
// Created by Xin Sun on 2020-12-28.
//

#include <iostream>
#include <cstring>

using namespace std;

char n1[1005];
char n2[1005];

int num1[1005];
int num2[1005];
int ans[1005];
int main()
{
    cin >> n1 >> n2;
    num1[0] = strlen(n1);
    num2[0] = strlen(n2);

    for (int i = 1, j = num1[0] -1; i <= num1[0]; i++, j--){
        num1[i] = n1[j] - '0';
    }

    for (int i = 1, j = num2[0] -1; i <= num2[0]; i++, j--){
        num2[i] = n2[j] - '0';
    }
    ans[0] = num1[0] + num2[0] -1;
    for(int i = 1; i <= num1[0]; i++){
        for(int j = 1; j <= num2[0]; j++)
        ans[i + j - 1] += num1[i] * num2[j];
    }

    for(int i = 1; i <= ans[0]; i++){
        if(ans[i] > 9){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
            if(i == ans[0]){
                ans[0]++;
            }
        }
    }

    for(int i = ans[0]; i >= 1; i--){
        cout << ans[i];
    }

    cout << endl;

    return 0;
}
