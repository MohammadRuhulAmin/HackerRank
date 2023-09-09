#include<bits/stdc++.h>
using namespace std;

string digit_sum(string n){
	if(n.length() == 1)return n;  
	int sum = 0;
	for(int i = 0;i<n.length();i++){
		sum += n[i] - '0';
	}
	return digit_sum(to_string(sum));
}
int main(){
	string n;
	int k;
	cin >> n >> k;
	int temp_ans = stoi(digit_sum(n))*k;
	if(temp_ans>9){
		cout << digit_sum(to_string(temp_ans));
	}
	else cout << temp_ans ;
	
	
	return 0;
}