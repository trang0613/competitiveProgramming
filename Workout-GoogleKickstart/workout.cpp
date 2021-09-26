#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n, k;
        cin >> n >> k;
        vector <int> minute;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            minute.push_back(m);
        }
        int left = 1;
        int right = minute[n-1];
        int ans;
        while(left<=right){
            int mid = (left+right)/2;
            int dOpt = mid;
            int sessions = 0;
            for(int i = 1; i < n; i++){
                int d = minute[i]-minute[i-1];
                if(d%dOpt==0){
                    sessions=sessions+d/dOpt-1;
                }
                else{
                    sessions=sessions+d/dOpt;
                }
            }
            if(sessions<=k){
                ans = dOpt;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
