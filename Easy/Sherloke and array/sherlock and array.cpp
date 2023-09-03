#include<bits/stdc++.h>
using namespace std;

string balancedSums(vector<int>vec,int sum,int range){
    int left_sum = 0;
    for(int i = 0;i<range;i++){
        if(left_sum == sum-vec[i]-left_sum)return "YES";
        else left_sum += vec[i];
    }
    return "NO";
}

int main(){
    int test;
    cin >> test;
    for(int t = 1;t<=test;t++){
        int sum = 0;
        int range;cin >> range;
        vector<int>vec;
        for(int x =  0;x<range;x++){
            int l;cin >> l;
            sum+= l;
            vec.push_back(l);
        }
        cout << balancedSums(vec,sum,range) << endl;
    }
    
    
    return 0;
}