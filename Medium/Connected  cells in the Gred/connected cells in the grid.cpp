#include<bits/stdc++.h>
using namespace std;

int traverse(vector<vector<int>>&matrix,int row,int col){
	if(row<0 || col<0 || row>=matrix.size() || col>=matrix[0].size())return 0;
	if(matrix[row][col] == 0)return 0;
	else{
		int size  = 1;
		matrix[row][col] = 0;
		for(int r = row-1;r<=row+1;r++){
			for(int c = col-1;c<=col+1;c++){
				if(r!=row || c!=col)
				size += traverse(matrix,r,c);
			}
		}
		return size;
	}
}

int main(){
	vector<vector<int>>matrix;
	int row,col;
	cin >> row >> col;
	for(int i = 0;i<row;i++){
		vector<int>temp;
		for(int j = 0;j<col;j++){
			int x;cin >> x;
			temp.push_back(x);
		}
		matrix.push_back(temp);
	}
	int ans = 0;
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			if(matrix[i][j] == 1){
				ans = max(traverse(matrix,i,j),ans);
			}
		}
	}
	cout << ans;
	
	return 0;
}