#include<bits/stdc++.h>
using namespace std;
#define row 3
#define col 3
#define range 9
vector<vector<int>> generated_magic_square;
bool is_square_matrix(vector<int>&vec){
	vector<vector<int>> matrix;
	for(int i = 0;i<row;i++){
		vector<int>temp;
		for(int j = 0;j<col;j++){
			temp.push_back(vec[3*i + j]);
		}
		matrix.push_back(temp);
	}
	// getting sum of first row
	int sum = 0;
	for(int i = 0;i<row;i++){
		sum += matrix[0][i];
	}
	// checking all rows and colums if sum same 
	for(int i = 0;i<row;i++){
		int row_sum = 0,col_sum = 0;
		for(int j = 0;j<col;j++){
			row_sum += matrix[i][j];
			col_sum += matrix[j][i];
		}
		if(row_sum!=sum || col_sum!=sum)return false;
	}
	// checking left diagonal is same sum 
	int left_diag_sum = 0;
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			if(i == j)left_diag_sum += matrix[i][j];
		}
	}
	if(left_diag_sum != sum)return false;
	
	// check right diagonal sum 
	int right_diag_sum = 0;
	for(int i = 0;i<row;i++){
		for(int j = 0;j<col;j++){
			if(i+j == row-1)right_diag_sum += matrix[i][j];
		}
	}
	if(right_diag_sum != sum)return false;
	return true;
}

void find_magic_square(){
	vector<int>number_list = {1,2,3,4,5,6,7,8,9};
	do{
		if(is_square_matrix(number_list)){
			generated_magic_square.push_back(number_list);
		}
	}while(next_permutation(number_list.begin(),number_list.end()));
}

int count_cost(vector<int>&given_matrix,vector<int> &generated_matrix){
	int cost = 0;
	for(int i = 0;i<range;i++){
		cost += abs(given_matrix[i]-generated_matrix[i]);
	}
	return cost;
}

int main(){
	int min_cost = INT_MAX;
	find_magic_square();
	vector<int>given_matrix;
	for(int i = 0;i<range;i++){
		int x;cin >> x;
		given_matrix.push_back(x);
	}
	for(int i = 0;i<generated_magic_square.size();i++){
		min_cost = min(count_cost(given_matrix,generated_magic_square[i]),min_cost);
	}
	cout << min_cost;
	return 0;
} 