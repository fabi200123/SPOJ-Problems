#include <bits/stdc++.h>

using namespace std;

int a, b, sum = 0;

int reverseSum(int sum){
    int aux = sum;
    sum = 0;
    while(aux){
        sum += aux % 10;
        sum*=10;
        aux/=10;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a;
        a = reverseSum(a);
        cin >> b;
        b = reverseSum(b);
        sum = reverseSum(a+b);
        cout << sum/10 <<'\n';
    }

    return 0;
}
