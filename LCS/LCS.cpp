#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int F[10000][10000];
string a, b;

int f(int i, int j){
    if(F[i][j] != -1){
        return F[i][j];
    }

    if(i==0 || j==0){
        F[i][j] = 0;
        return F[i][j];
    }

    if(a[i] == b[j]){
        F[i][j] = f(i-1,j-1)+1;
    }
    else{
        F[i][j] = max(f(i,j-1),f(i-1,j)); 
    }
    return F[i][j];
}

int main() {
    for(int i = 0; i<10000; i++){
        for(int j = 0; j<10000;j++){
            F[i][j] = -1;
        }
    }
    cin >> a;
    cin >> b;
    int n = a.length();
    int m = b.length();
    a = " "+a;
    b = " "+b;
    cout << f(n,m);
}
