#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int range,day;
	int ans = 0;
	scanf("%d%d",&range,&day);
	int count_next = day;
	int arr[range];
	for(int i = 0;i<range;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i = 0;i<range-day;i++){
		int len = 0;
		vector<int>temp;
		for(int j = i;len!=day;j++){
			temp.push_back(arr[j]);
			len++;
		}
		sort(temp.begin(),temp.end());
		if(day%2 == 0){
			int midx = day/2-1;
			int midy = day/2;
			int sum = (temp[midx]+temp[midy]);
			if(arr[count_next]>=2*sum)ans++;
		}
		else{
			int midz = ceil(day/2);
			if(arr[count_next]>=2*temp[midz])ans++;
			
		}
		count_next++;
	}
	printf("%d",ans);
	
	
	return 0;
}