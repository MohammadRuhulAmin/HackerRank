#include<bits/stdc++.h>
using namespace std;


string make_possible_pattern(int p_row,int p_col,int ar_row,int ar_col,vector<vector<char>>&arr_str,vector<vector<char>>&pat_str){
	bool flag = true;
	for(int i = 0;i<=ar_row-p_row;i++){
		for(int j = 0;j<=ar_col-p_col;j++){
			if(arr_str[i][j] == pat_str[0][0]){
				flag = true;
				for(int m=0,k=i;m<p_row;m++,k++){
					for(int n=0,l=j;n<p_col;n++,l++){
						if(pat_str[m][n]!= arr_str[k][l]){
							flag = false;
							break;
						}
						else continue;
					}
					if(!flag)break;
				}
				if(flag == true)return "YES";
			}
		}
	}
	return "NO";
}

int main(){
	int testcase;
	cin >> testcase;
	for(int t = 1;t<=testcase;t++){
		vector<vector<char>>arr_str;
		vector<vector<char>>pat_str;
		int ar_row,ar_col;
		cin >> ar_row >> ar_col;
		for(int i = 0;i<ar_row;i++){
			vector<char>temp;
			for(int j = 0;j<ar_col;j++){
				char x;cin >> x;
				temp.push_back(x);
			}
			arr_str.push_back(temp);
		}
		int p_row,p_col;
		cin >> p_row >> p_col;
	
		for(int i=0;i<p_row;i++){
			vector<char>temp;
			for(int j= 0;j<p_col;j++){
				char x;cin >> x;
				temp.push_back(x);
			}
			pat_str.push_back(temp);
		}
		
		cout << make_possible_pattern(p_row,p_col,ar_row,ar_col,arr_str,pat_str) << endl;	
	}
	return 0;
}