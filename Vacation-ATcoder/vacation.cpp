#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int a[N], b[N], c[N];
    int F[N][3];
    for(int i = 0; i<N;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
 
    F[0][0] = a[0];
    F[0][1] = b[0];
    F[0][2] = c[0];
 
    for(int i = 1; i<N; i++){
        F[i][0] = max(F[i-1][1]+a[i], F[i-1][2]+a[i]);
        F[i][1] = max(F[i-1][0]+b[i], F[i-1][2]+b[i]);
        F[i][2] = max(F[i-1][0]+c[i], F[i-1][1]+c[i]);
    }
 
    int tmp = max(F[N-1][0], F[N-1][1]);
    int res = max(tmp, F[N-1][2]);
    cout << res;
  
}
