#include<bits/stdc++.h>
using namespace std;

int lilys_homework(int range,vector<int>arr_org){
	int result = INT_MAX;
	vector<int>temp_arr(arr_org);
	sort(temp_arr.begin(),temp_arr.end(),greater<int>());
	for(int x = 0;x<2;x++){
		int count = 0;
		if(x)reverse(temp_arr.begin(),temp_arr.end());
		vector<int>arr(arr_org);
		unordered_map<int,int>cont;
		for(int i = 0;i<range;i++){
			cont[arr[i]] = i;
		}
		for(int i = 0;i<range;i++){
			if(arr[i] == temp_arr[i])continue;
			else{
				int p = arr[i];
				int q = temp_arr[i];
				swap(arr[i],arr[cont[q]]);
				cont[p] = cont[q];
				cont[q] = i;
				count++;
			}
		}
		cout << count << endl;
		result = min(result,count);
		
	}
	return result;
	
}

int main(){
	vector<int>arr;
	int range;
	cin >> range;
	for(int i = 0;i<range;i++){
		int x;cin  >> x;
		arr.push_back(x);
	}
	cout << lilys_homework(range,arr);
	
	
	return 0;
}