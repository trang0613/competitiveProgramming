#include <iostream> 
#include <vector>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    for(int test = 0; test<testCase; test++){
        int n;
        cin >> n;
        int arr[n];
        int sumSub = 0;
        int maxai = -10007;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            maxai = max(arr[i],maxai);
            if(arr[i]>=0){
                sumSub += arr[i];
            }
        }
        if(maxai<0){
            sumSub = maxai;
        }
        int index = 0;
        int maxSum = -10007;
        int curSum = 0;
        for(int index = 0; index<n; index++){
            curSum = max(arr[index],curSum+arr[index]);
            maxSum = max(maxSum, curSum);
        }       
        cout << maxSum << " " << sumSub << endl;
    }
    return 0;
}
