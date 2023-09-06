#include<bits/stdc++.h>
using namespace std;
int allpossiblesubstring(string s){
	map<string,int>sub_string_table;
	for(int i = 0;i<s.size();++i){
		for(int j = 1;j<s.size()-i+1;++j){
			string temp =  s.substr(i,j) ;
			sort(temp.begin(),temp.end());
			if(sub_string_table.count(temp) == 0)sub_string_table[temp] = 1;
			else sub_string_table[temp] += 1;
		}
	}
	map<string,int>::iterator it;
	int count = 0;
	for(it = sub_string_table.begin();it!=sub_string_table.end();it++){
		int value = it->second;
		if(value>1){
			count += (value*(value-1)/2);
		}
	}
	return count;
}

int main(){
	int test;
	cin >> test;
	for(int x = 1;x<=test;x++){
		string s;
		cin >> s;
		cout << allpossiblesubstring(s) << endl;
	}
	
	
	return 0;
}