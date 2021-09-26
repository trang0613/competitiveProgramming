// https://www.spoj.com/problems/EDIST/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
int F[2001][2001];

int lev(int i, int j){
    if(F[i][j] != -1){
        return F[i][j];
    }

    if(i == 0){
        F[i][j] = j;
        return F[i][j];
    }
    else if(j == 0){
        F[i][j] = i;
        return F[i][j];
    }

    if(a[i]==b[j]){
        F[i][j] = lev(i-1,j-1);
    }
    else{
        int tmp = min(lev(i-1,j-1)+1, lev(i,j-1)+1);
        F[i][j] = min( tmp, lev(i-1,j)+1);
    }

    return F[i][j];
}
