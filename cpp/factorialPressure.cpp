#include <iostream>
using namespace std;

int multiply(int i, int factorial[], int size){
    int carry = 0;
    for(int j = 0; j < size; j++){
        int product = factorial[j] * i + carry;
        factorial[j] = product % 10;
        carry = product/10;
    }
    while(carry){
        factorial[size] = carry%10;
        carry /= 10;
        size++;
    }
    return size;
}
void fact(int n){
    int factorial[10000];
    factorial[0] = 1;
    int size = 1;
    for(int i = 2; i <= n; i++){
        size = multiply(i, factorial, size);
    }
    for(int i = size - 1; i >= 0; i--){
        cout << factorial[i];
    }
    cout << endl;
}
int main(){
    int a,b;
    cin >> a >> b;
    int gcd = (a < b) ? a : b;
    fact(a);
    return 0;
}
