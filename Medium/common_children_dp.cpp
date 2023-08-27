#include<bits/stdc++.h>
using namespace std;

#define maximum 5005
int dp[5005][5005];

int lcs(string x,string y){
    int lenx = x.length();
    int leny = y.length();
    for(int i = 0;i<=lenx;i++){
        for(int j = 0;j<=leny;j++){
            if(i == 0 || j == 0)dp[i][j] = 0;
            else if(x[i-1] == y[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[lenx][leny];
}

int main(){
    string x,y;
    cin >> x >> y;

    memset(dp,-1,sizeof(dp));
    cout << lcs(x,y);
    
    
    return 0;
}