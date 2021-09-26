#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int temp;
    int left = 0;
    int right = 0;
    vector<int> tree;
    for(int i =0;i<n;i++){
        cin >> temp;
        tree.push_back(temp);
        if(temp>right){
            right = temp;
        }
    }
    long long int height;
    long long int sum;
    while(left<=right){
        height = (left+right)/2;
        sum = 0;
        for(int i =0;i<n;i++){
            if(tree[i]>height){
                sum+=tree[i]-height;
            }
        }
        if(sum>m){
            left = height+1;
        }
        else if(sum<m){
            right = height-1;
        }
        else{
            height;
            break;
        }
    }
    if(sum<m && left>right){
        height--;
    }
    cout << height;
}

int main(){
    solve();
}
