// using recursion 
#include<bits/stdc++.h>
using namespace std;
#define maximum 9000

int dp[maximum][maximum];

int lcs(string x,string y,int i,int j){
	if (x[i] == '\0' || y[j] == '\0')return 0;
	else if(dp[i][j]!=-1)return dp[i][j];
	else if(x[i] == y[j]){
		dp[i][j] = 1+lcs(x,y,i+1,j+1);
		return dp[i][j];
	}
	else{
		dp[i][j] =  max(lcs(x,y,i+1,j),lcs(x,y,i,j+1));
		return dp[i][j];
	}
}

int main(){
	string x,y;
	cin >> x >> y;
	int len_x = x.length();
	int len_y = y.length();
	memset(dp,-1,sizeof(dp));
	cout << lcs(x,y,0,0);

	
	
	return 0;
}