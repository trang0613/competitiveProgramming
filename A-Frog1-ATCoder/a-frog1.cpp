#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
 
int main() {
    int N;
    cin >> N;
    int h[N], F[N];
    for(int i = 1; i<=N; i++){
        cin >> h[i];
    }
    F[1] = 0;
    F[2] = abs(h[2]-h[1]);
    for(int i=3; i<=N; i++){
        F[i] = min( F[i-1]+abs(h[i-1]-h[i]) , F[i-2]+abs(h[i-2]-h[i]) );
    }
    cout << F[N];
}
