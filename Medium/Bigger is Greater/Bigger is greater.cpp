#include<bits/stdc++.h>
using namespace std;

vector<char> next_permutation(vector<char>str,int iterator){
	
	int prev_index = iterator-1;
	int curr_index = iterator;
	for(int i = iterator;i<str.size();i++){
		if(str[prev_index]<str[i] && str[i] <=str[curr_index]){
			curr_index = i;
		}
	}
	swap(str[prev_index],str[curr_index]);
	sort(str.begin()+iterator,str.end());
	return str;
}

int main(){
	int test;
	cin >> test ;
	for(int l = 1;l<=test;l++){
		string s;
		cin >> s;
		vector<char>str;
		set<char>check;
		for(int i = 0;i<s.size();i++){
			str.push_back(s[i]);
			check.insert(s[i]);
		}
		if(check.size() == 1) cout << "no answer\n";
		else{
			int iterator = -1;
			for(int i = str.size()-1;i>0;i--){
				if(str[i]>str[i-1]){
					iterator = i;
					break;
				}
			}
			if(iterator == -1)cout << "no answer\n";
			else{
				vector<char> ans = next_permutation(str,iterator);
				for(int i = 0;i<ans.size();i++)cout << ans[i];
				cout << endl;
			}
		}			
	}
	return 0;
}