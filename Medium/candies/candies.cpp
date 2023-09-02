#include<bits/stdc++.h>
using namespace std;

long candies(long n, vector<long> arr) {
    vector<long>left_check(n,1);
    vector<long>right_check(n,1);
    for(long i = 1;i<n;i++){
        if(arr[i-1]<arr[i]){
            left_check[i]=left_check[i-1]+1;
        }
    }
    for(long i = n-1;i>0;i--){
        if(arr[i-1]>arr[i]){
            right_check[i-1] = right_check[i]+1;
        }
    }
    long ans = 0;
    for(long i = 0;i<n;i++){
        ans += max(left_check[i],right_check[i]);
    }
    return ans;
}


int main(){
    
        
    long n;
    cin >> n;
    vector<long>arr;
    for(long i = 0;i<n;i++){
        long x;
        cin >> x;
        arr.push_back(x);
    }
    cout << candies(n,arr);
    
    return 0;
}

