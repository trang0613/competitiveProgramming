#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int N, W;
int w[101], v[101];
long long int F[101][100001];
 
long long int f(int i, int j){
    if(F[i][j] != -1){
        return F[i][j];
    }
 
    if(i == 0 || j == 0){
        F[i][j] = 0;
        return F[i][j];
    }
  
    if(w[i]<=j){
        F[i][j] = max(f(i-1,j-w[i])+v[i],f(i-1,j));
    }
    else{
        F[i][j] = f(i-1,j);
    }
    
    return F[i][j];
    
}
 
 
 
int main() {
    for(int i = 0; i<101; i++){
            for(int j = 0; j<100001;j++){
                F[i][j] = -1;
        }
    }
    cin >> N >> W;
    for(int i = 1; i<=N; i++){
        cin >> w[i] >> v[i];
    }
    
    cout << f(N,W);
}
