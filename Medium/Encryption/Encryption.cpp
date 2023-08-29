#include<bits/stdc++.h>
using namespace std;

string encryption(int row,int col,string str){
	string ans = "";
	vector<vector<char>>vec;
	int index = 0;
	for(int i = 0;i<row;i++){
		vector<char>temp;
		for(int j=0;j<col;j++){
			if(index>=str.length()){
				temp.push_back(' ');
				index++;
			}
			else{
				temp.push_back(str[index]);
				index++;
			}
			
		}
		vec.push_back(temp);
	}	
	
	int count_index =0;
	for(int i = 0;i<col;i++){
		string temp = "";
		for(int j = 0;j<row;j++){
			temp += vec[j][i];
			count_index++;
		}
		char lc = temp.back();
		if(lc != ' ')temp+=' ';
		ans += temp;
	}
	char ls = ans.back();
	if(ls == ' ')ans.pop_back();
	return ans;

}

int main(){
	string str;
	cin >> str;
	int length = str.length();
	int row = floor(sqrt(length));
	int col = ceil(sqrt(length));
	if(row*col<length)row = col;
	cout << encryption(row,col,str);
	
	
	return 0;
}