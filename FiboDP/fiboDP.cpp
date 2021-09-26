#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int F[10000];

long long int fibo(int n){
    if (F[n] != -1){
        return F[n];
    }
    else if(n==0 || n==1){
        F[n]=n;
        return F[n];
    }
    F[n] = fibo(n-1)+fibo(n-2);
    return F[n];
}

int main() { 
    for(int i = 0; i<10000; i++){
        F[i] = -1;
    }
    int n;
    cin >> n;
    cout << fibo(n);
    
}
