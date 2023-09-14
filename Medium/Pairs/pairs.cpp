#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int>&arr,int val){
    int high = arr.size()-1;
    int low = 0;
    int mid;
    while(low<=high){
        int mid = (high+low)/2;
        if(arr[mid] == val)return true;
        else if(arr[mid]>val)high = mid-1;
        else low = mid+1;
    }
    return false;
}


int main(){
    int k;
    int ans = 0;
    int range;cin >> range >> k;
    vector<int>arr;
    for(int i = 0;i<range;i++){
        int x;cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i<range;i++){
        int val = arr[i] - k;
        if(binarySearch(arr,val))ans++;
        
    }
    cout << ans <<endl ;

    return 0;
}