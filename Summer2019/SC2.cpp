#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int F[10000][10000];
int a[3001], b[3001];

int isIn(int num, int arr[], int len){
    int ans = 0;
    for(int i = 1; i<=len; i++){
        if(arr[i]==num){
            ans = 1;
            break;
        }
    }
    return ans;
}

int f(int i, int j){
    if(F[i][j] != -1){
        return F[i][j];
    }

    if(i==0 || j==0){
        F[i][j] = 0;
        return F[i][j];
    }
    else if(i==1 || j==1){
        F[i][j] = max(isIn(a[i],b,j), isIn(b[j],a,i));
        return F[i][j];
    }

    if(a[i] == b[j]){
        F[i][j] = f(i-2,j-2)+1;
    }
    else{
        F[i][j] = max(f(i,j-1),f(i-1,j)); 
    }
    return F[i][j];
}

int main() {
    int testCase;
    cin >> testCase;
    for(int test = 0; test < testCase; test++){
        for(int i = 0; i<10000; i++){
            for(int j = 0; j<10000;j++){
                F[i][j] = -1;
            }
        }
        int n, m;
        cin >> n;
        cin >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];    
        }
        for(int j = 1; j <= m; j++){
            cin >> b[j];
        }
        cout << f(n,m) << endl;
    }
    return 0;
}
